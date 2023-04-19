///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2019, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// \brief Tiny printf, sprintf and (v)snprintf implementation, optimized for speed on
//        embedded systems with a very limited resources. These routines are thread
//        safe and reentrant!
//        Use this instead of the bloated standard/newlib printf cause these use
//        malloc for printf (and may not be thread safe).
//
///////////////////////////////////////////////////////////////////////////////

#include "stdbool.h"
#include "printf.h"
#include "st7789.h"


// define this globally (e.g. gcc -DPRINTF_INCLUDE_CONFIG_H ...) to include the
// printf_config.h header file
// default: undefined
#ifdef PRINTF_INCLUDE_CONFIG_H
#include "printf_config.h"
#endif

// 'ntoa' conversion buffer size, this must be big enough to hold one converted
// numeric number including padded zeros (dynamically created on stack)
// default: 32 byte
#ifndef PRINTF_NTOA_BUFFER_SIZE
#define PRINTF_NTOA_BUFFER_SIZE    32U
#endif

// 'ftoa' conversion buffer size, this must be big enough to hold one converted
// float number including padded zeros (dynamically created on stack)
// default: 32 byte
#ifndef PRINTF_FTOA_BUFFER_SIZE
#define PRINTF_FTOA_BUFFER_SIZE    40U
#endif

// support for the floating point type (%f)
// default: activated
#ifndef PRINTF_DISABLE_SUPPORT_FLOAT
#define PRINTF_SUPPORT_FLOAT
#endif

// support for exponential floating point notation (%e/%g)
// default: activated
#ifndef PRINTF_DISABLE_SUPPORT_EXPONENTIAL
#define PRINTF_SUPPORT_EXPONENTIAL
#endif

// define the default floating point precision
// default: 6 digits
#ifndef PRINTF_DEFAULT_FLOAT_PRECISION
#define PRINTF_DEFAULT_FLOAT_PRECISION  6U
#endif

// define the largest float suitable to print with %f
// default: 1e9
#ifndef PRINTF_MAX_FLOAT
#define PRINTF_MAX_FLOAT  1e18
#endif

// support for the long long types (%llu or %p)
// default: activated
#ifndef PRINTF_DISABLE_SUPPORT_LONG_LONG
#define PRINTF_SUPPORT_LONG_LONG
#endif

// support for the ptrdiff_t type (%t)
// ptrdiff_t is normally defined in <stddef.h> as long or long long type
// default: activated
#ifndef PRINTF_DISABLE_SUPPORT_PTRDIFF_T
#define PRINTF_SUPPORT_PTRDIFF_T
#endif

///////////////////////////////////////////////////////////////////////////////

// internal flag definitions
#define FLAGS_ZEROPAD   (1U <<  0U)
#define FLAGS_LEFT      (1U <<  1U)
#define FLAGS_PLUS      (1U <<  2U)
#define FLAGS_SPACE     (1U <<  3U)
#define FLAGS_HASH      (1U <<  4U)
#define FLAGS_UPPERCASE (1U <<  5U)
#define FLAGS_CHAR      (1U <<  6U)
#define FLAGS_SHORT     (1U <<  7U)
#define FLAGS_LONG      (1U <<  8U)
#define FLAGS_LONG_LONG (1U <<  9U)
#define FLAGS_PRECISION (1U << 10U)
#define FLAGS_ADAPT_EXP (1U << 11U)


// import float.h for DBL_MAX
#if defined(PRINTF_SUPPORT_FLOAT)
#include "float.h"
#include "math.h"
#endif


// output function type
typedef void (*out_fct_type)(char character, void* buffer, size_t idx, size_t maxlen);


// wrapper (used as buffer) for output function type
typedef struct {
  void  (*fct)(char character, void* arg);
  void* arg;
} out_fct_wrap_type;


// internal buffer output
static void _out_buffer(char character, void* buffer, size_t idx, size_t maxlen)
{
  if (idx < maxlen) {
    ((char*)buffer)[idx] = character;
  }
}


// internal null output
static void _out_null(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)character; (void)buffer; (void)idx; (void)maxlen;
}


// internal _putchar wrapper
static void _out_char(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    _putchar(character);
  }
}


// internal output function wrapper
static void _out_fct(char character, void* buffer, size_t idx, size_t maxlen)
{
  (void)idx; (void)maxlen;
  if (character) {
    // buffer is the output fct pointer
    ((out_fct_wrap_type*)buffer)->fct(character, ((out_fct_wrap_type*)buffer)->arg);
  }
}


// internal secure strlen
// \return The length of the string (excluding the terminating 0) limited by 'maxsize'
static unsigned int _strnlen_s(const char* str, size_t maxsize)
{
  const char* s;
  for (s = str; *s && maxsize--; ++s);
  return (unsigned int)(s - str);
}


// internal test if char is a digit (0-9)
// \return true if char is a digit
static bool _is_digit(char ch)
{
  return (ch >= '0') && (ch <= '9');
}


// internal ASCII string to unsigned int conversion
static unsigned int _atoi(const char** str)
{
  unsigned int i = 0U;
  while (_is_digit(**str)) {
    i = i * 10U + (unsigned int)(*((*str)++) - '0');
  }
  return i;
}


// output the specified string in reverse, taking care of any zero-padding
static size_t _out_rev(out_fct_type out, char* buffer, size_t idx, size_t maxlen, const char* buf, size_t len, unsigned int width, unsigned int flags)
{
  const size_t start_idx = idx;
  size_t i;

  // pad spaces up to given width
  if (!(flags & FLAGS_LEFT) && !(flags & FLAGS_ZEROPAD)) {
    for (i = len; i < width; i++) {
      out(' ', buffer, idx++, maxlen);
    }
  }

  // reverse string
  while (len) {
    out(buf[--len], buffer, idx++, maxlen);
  }

  // append pad spaces up to given width
  if (flags & FLAGS_LEFT) {
    while (idx - start_idx < width) {
      out(' ', buffer, idx++, maxlen);
    }
  }

  return idx;
}


// internal itoa format
static size_t _ntoa_format(out_fct_type out, char* buffer, size_t idx, size_t maxlen, char* buf, size_t len, bool negative, unsigned int base, unsigned int prec, unsigned int width, unsigned int flags)
{
  // pad leading zeros
  if (!(flags & FLAGS_LEFT)) {
    if (width && (flags & FLAGS_ZEROPAD) && (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
      width--;
    }
    while ((len < prec) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = '0';
    }
    while ((flags & FLAGS_ZEROPAD) && (len < width) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = '0';
    }
  }

  // handle hash
  if (flags & FLAGS_HASH) {
    if (!(flags & FLAGS_PRECISION) && len && ((len == prec) || (len == width))) {
      len--;
      if (len && (base == 16U)) {
        len--;
      }
    }
    if ((base == 16U) && !(flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'x';
    }
    else if ((base == 16U) && (flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'X';
    }
    else if ((base == 2U) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'b';
    }
    if (len < PRINTF_NTOA_BUFFER_SIZE) {
      buf[len++] = '0';
    }
  }

  if (len < PRINTF_NTOA_BUFFER_SIZE) {
    if (negative) {
      buf[len++] = '-';
    }
    else if (flags & FLAGS_PLUS) {
      buf[len++] = '+';  // ignore the space if the '+' exists
    }
    else if (flags & FLAGS_SPACE) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
}


// internal itoa for 'long' type
static size_t _ntoa_long(out_fct_type out, char* buffer, size_t idx, size_t maxlen, unsigned long value, bool negative, unsigned long base, unsigned int prec, unsigned int width, unsigned int flags)
{
  char buf[PRINTF_NTOA_BUFFER_SIZE];
  size_t len = 0U;

  // no hash for 0 values
  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  // write if precision != 0 and value is != 0
  if (!(flags & FLAGS_PRECISION) || value) {
    do {
      const char digit = (char)(value % base);
      buf[len++] = digit < 10 ? '0' + digit : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
      value /= base;
    } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));
  }

  return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}


// internal itoa for 'long long' type
#if defined(PRINTF_SUPPORT_LONG_LONG)
static size_t _ntoa_long_long(out_fct_type out, char* buffer, size_t idx, size_t maxlen, unsigned long long value, bool negative, unsigned long long base, unsigned int prec, unsigned int width, unsigned int flags)
{
  char buf[PRINTF_NTOA_BUFFER_SIZE];
  size_t len = 0U;

  // no hash for 0 values
  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  // write if precision != 0 and value is != 0
  if (!(flags & FLAGS_PRECISION) || value) {
    do {
      const char digit = (char)(value % base);
      buf[len++] = digit < 10 ? '0' + digit : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
      value /= base;
    } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));
  }

  return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}
#endif  // PRINTF_SUPPORT_LONG_LONG


#if defined(PRINTF_SUPPORT_FLOAT)

#if defined(PRINTF_SUPPORT_EXPONENTIAL)
// forward declaration so that _ftoa can switch to exp notation for values > PRINTF_MAX_FLOAT
static size_t _etoa(out_fct_type out, char* buffer, size_t idx, size_t maxlen, double value, unsigned int prec, unsigned int width, unsigned int flags);
#endif

// internal ftoa for fixed decimal floating point
static size_t _ftoa(out_fct_type out, char* buffer, size_t idx, size_t maxlen, double value, unsigned int prec, unsigned int width, unsigned int flags)
{
  char buf[PRINTF_FTOA_BUFFER_SIZE];
  size_t len  = 0U;
  double diff = 0.0;
  bool negative;
  long long whole;
  double tmp;
  unsigned long long frac;

  // powers of 10
  static const double pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000,
                                  100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000, 10000000000000000000 };

  // test for special values
  if (isnan(value))
    return _out_rev(out, buffer, idx, maxlen, "nan", 3, width, flags);
  if (value < -DBL_MAX)
    return _out_rev(out, buffer, idx, maxlen, "fni-", 4, width, flags);
  if (value > DBL_MAX)
    return _out_rev(out, buffer, idx, maxlen, (flags & FLAGS_PLUS) ? "fni+" : "fni", (flags & FLAGS_PLUS) ? 4U : 3U, width, flags);

  // test for very large values
  // standard printf behavior is to print EVERY whole number digit -- which could be 100s of characters overflowing your buffers == bad
  if ((value > PRINTF_MAX_FLOAT) || (value < -PRINTF_MAX_FLOAT)) {
#if defined(PRINTF_SUPPORT_EXPONENTIAL)
    return _etoa(out, buffer, idx, maxlen, value, prec, width, flags);
#else
    return 0U;
#endif
  }
  
  // test for negative
  negative = false;
  if (value < 0) {
    negative = true;
    value = 0 - value;
  }

  // set default precision, if not set explicitly
  if (!(flags & FLAGS_PRECISION)) {
    prec = PRINTF_DEFAULT_FLOAT_PRECISION;
  }
  // limit precision to 9, cause a prec >= 10 can lead to overflow errors
  while ((len < PRINTF_FTOA_BUFFER_SIZE) && (prec > 19U)) {
    buf[len++] = '0';
    prec--;
  }

  whole = (long long)value;
  tmp = (value - whole) * pow10[prec];
  frac = (unsigned long long)tmp;
  diff = tmp - frac;

  if (diff > 0.5) {
    ++frac;
    // handle rollover, e.g. case 0.99 with prec 1 is 1.0
    if (frac >= pow10[prec]) {
      frac = 0;
      ++whole;
    }
  }
  else if (diff < 0.5) {
  }
  else if ((frac == 0U) || (frac & 1U)) {
    // if halfway, round up if odd OR if last digit is 0
    ++frac;
  }

  if (prec == 0U) {
    diff = value - (double)whole;
    if ((!(diff < 0.5) || (diff > 0.5)) && (whole & 1)) {
      // exactly 0.5 and ODD, then round up
      // 1.5 -> 2, but 2.5 -> 2
      ++whole;
    }
  }
  else {
    unsigned int count = prec;
    // now do fractional part, as an unsigned number
    while (len < PRINTF_FTOA_BUFFER_SIZE) {
      --count;
      buf[len++] = (char)(48U + (frac % 10U));
      if (!(frac /= 10U)) {
        break;
      }
    }
    // add extra 0s
    while ((len < PRINTF_FTOA_BUFFER_SIZE) && (count-- > 0U)) {
      buf[len++] = '0';
    }
    if (len < PRINTF_FTOA_BUFFER_SIZE) {
      // add decimal
      buf[len++] = '.';
    }
  }

  // do whole part, number is reversed
  while (len < PRINTF_FTOA_BUFFER_SIZE) {
    buf[len++] = (char)(48 + (whole % 10));
    if (!(whole /= 10)) {
      break;
    }
  }

  // pad leading zeros
  if (!(flags & FLAGS_LEFT) && (flags & FLAGS_ZEROPAD)) {
    if (width && (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
      width--;
    }
    while ((len < width) && (len < PRINTF_FTOA_BUFFER_SIZE)) {
      buf[len++] = '0';
    }
  }

  if (len < PRINTF_FTOA_BUFFER_SIZE) {
    if (negative) {
      buf[len++] = '-';
    }
    else if (flags & FLAGS_PLUS) {
      buf[len++] = '+';  // ignore the space if the '+' exists
    }
    else if (flags & FLAGS_SPACE) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
}

#if defined(PRINTF_SUPPORT_EXPONENTIAL)
// internal ftoa variant for exponential floating-point type, contributed by Martijn Jasperse <m.jasperse@gmail.com>
static size_t _etoa(out_fct_type out, char* buffer, size_t idx, size_t maxlen, double value, unsigned int prec, unsigned int width, unsigned int flags)
{
  bool negative;
  union {
      uint64_t U;
      double   F;
  } conv;
  int exp2;
  int expval;
  double z;
  double z2;
  unsigned int minwidth;
  unsigned int fwidth;
  size_t start_idx;

  // check for NaN and special values
  if (isnan(value) || (value > DBL_MAX) || (value < -DBL_MAX)) {
    return _ftoa(out, buffer, idx, maxlen, value, prec, width, flags);
  }

  // determine the sign
  negative = value < 0;
  if (negative) {
    value = -value;
  }

  // default precision
  if (!(flags & FLAGS_PRECISION)) {
    prec = PRINTF_DEFAULT_FLOAT_PRECISION;
  }

  // determine the decimal exponent
  // based on the algorithm by David Gay (https://www.ampl.com/netlib/fp/dtoa.c)

  conv.F = value;
  exp2 = (int)((conv.U >> 52U) & 0x07FFU) - 1023;           // effectively log2
  conv.U = (conv.U & ((1ULL << 52U) - 1U)) | (1023ULL << 52U);  // drop the exponent so conv.F is now in [1,2)
  // now approximate log10 from the log2 integer part and an expansion of ln around 1.5
  expval = (int)(0.1760912590558 + exp2 * 0.301029995663981 + (conv.F - 1.5) * 0.289529654602168);
  // now we want to compute 10^expval but we want to be sure it won't overflow
  exp2 = (int)(expval * 3.321928094887362 + 0.5);
  z  = expval * 2.302585092994046 - exp2 * 0.6931471805599453;
  z2 = z * z;
  conv.U = (uint64_t)(exp2 + 1023) << 52U;
  // compute exp(z) using continued fractions, see https://en.wikipedia.org/wiki/Exponential_function#Continued_fractions_for_ex
  conv.F *= 1 + 2 * z / (2 - z + (z2 / (6 + (z2 / (10 + z2 / 14)))));
  // correct for rounding errors
  if (value < conv.F) {
    expval--;
    conv.F /= 10;
  }

  // the exponent format is "%+03d" and largest value is "307", so set aside 4-5 characters
  minwidth = ((expval < 100) && (expval > -100)) ? 4U : 5U;

  // in "%g" mode, "prec" is the number of *significant figures* not decimals
  if (flags & FLAGS_ADAPT_EXP) {
    // do we want to fall-back to "%f" mode?
    if ((value >= 1e-4) && (value < 1e6)) {
      if ((int)prec > expval) {
        prec = (unsigned)((int)prec - expval - 1);
      }
      else {
        prec = 0;
      }
      flags |= FLAGS_PRECISION;   // make sure _ftoa respects precision
      // no characters in exponent
      minwidth = 0U;
      expval   = 0;
    }
    else {
      // we use one sigfig for the whole part
      if ((prec > 0) && (flags & FLAGS_PRECISION)) {
        --prec;
      }
    }
  }

  // will everything fit?
  fwidth = width;
  if (width > minwidth) {
    // we didn't fall-back so subtract the characters required for the exponent
    fwidth -= minwidth;
  } else {
    // not enough characters, so go back to default sizing
    fwidth = 0U;
  }
  if ((flags & FLAGS_LEFT) && minwidth) {
    // if we're padding on the right, DON'T pad the floating part
    fwidth = 0U;
  }

  // rescale the float value
  if (expval) {
      if((value >= DBL_MIN || value <= -DBL_MIN) && (conv.F >= DBL_MIN || conv.F <= -DBL_MIN))
          value /= conv.F;
  }
 
  // output the floating part
  start_idx = idx;
  idx = _ftoa(out, buffer, idx, maxlen, negative ? -value : value, prec, fwidth, flags & ~FLAGS_ADAPT_EXP);

  // output the exponent part
  if (minwidth) {
    // output the exponential symbol
    out((flags & FLAGS_UPPERCASE) ? 'E' : 'e', buffer, idx++, maxlen);
    // output the exponent value
    idx = _ntoa_long(out, buffer, idx, maxlen, (expval < 0) ? -expval : expval, expval < 0, 10, 0, minwidth-1, FLAGS_ZEROPAD | FLAGS_PLUS);
    // might need to right-pad spaces
    if (flags & FLAGS_LEFT) {
      while (idx - start_idx < width) out(' ', buffer, idx++, maxlen);
    }
  }
  return idx;
}
#endif  // PRINTF_SUPPORT_EXPONENTIAL
#endif  // PRINTF_SUPPORT_FLOAT


// internal vsnprintf
static int _vsnprintf(out_fct_type out, char* buffer, const size_t maxlen, const char* format, va_list va)
{
    unsigned int flags, width, precision, n;
    size_t idx = 0U;
    bool is_ll;

    if (!buffer) {
        // use null output function
        out = _out_null;
    }

    while (*format)
    {
        // format specifier?  %[flags][width][.precision][length]
        if (*format != '%') {
            // no
            out(*format, buffer, idx++, maxlen);
            format++;
            continue;
        }
        else {
            // yes, evaluate it
            format++;
        }

        // evaluate flags
        flags = 0U;
        do {
            switch (*format) {
            case '0': flags |= FLAGS_ZEROPAD; format++; n = 1U; break;
            case '-': flags |= FLAGS_LEFT;    format++; n = 1U; break;
            case '+': flags |= FLAGS_PLUS;    format++; n = 1U; break;
            case ' ': flags |= FLAGS_SPACE;   format++; n = 1U; break;
            case '#': flags |= FLAGS_HASH;    format++; n = 1U; break;
            default:                                   n = 0U; break;
            }
        } while (n);

        // evaluate width field
        width = 0U;
        if (_is_digit(*format)) {
            width = _atoi(&format);
        }
        else if (*format == '*') {
            const int w = va_arg(va, int);
            if (w < 0) {
                flags |= FLAGS_LEFT;    // reverse padding
                width = (unsigned int)-w;
            }
            else {
                width = (unsigned int)w;
            }
            format++;
        }

        // evaluate precision field
        precision = 0U;
        if (*format == '.') {
            flags |= FLAGS_PRECISION;
            format++;
            if (_is_digit(*format)) {
                precision = _atoi(&format);
            }
            else if (*format == '*') {
                const int prec = (int)va_arg(va, int);
                precision = prec > 0 ? (unsigned int)prec : 0U;
                format++;
            }
        }

        // evaluate length field
        switch (*format) {
        case 'l':
            flags |= FLAGS_LONG;
            format++;
            if (*format == 'l') {
                flags |= FLAGS_LONG_LONG;
                format++;
            }
            break;
        case 'h':
            flags |= FLAGS_SHORT;
            format++;
            if (*format == 'h') {
                flags |= FLAGS_CHAR;
                format++;
            }
            break;
#if defined(PRINTF_SUPPORT_PTRDIFF_T)
        case 't':
            flags |= (sizeof(ptrdiff_t) == sizeof(long) ? FLAGS_LONG : FLAGS_LONG_LONG);
            format++;
            break;
#endif
        case 'j':
            flags |= (sizeof(intmax_t) == sizeof(long) ? FLAGS_LONG : FLAGS_LONG_LONG);
            format++;
            break;
        case 'z':
            flags |= (sizeof(size_t) == sizeof(long) ? FLAGS_LONG : FLAGS_LONG_LONG);
            format++;
            break;
        default:
            break;
        }

        // evaluate specifier
        switch (*format) {
        case 'd':
        case 'i':
        case 'u':
        case 'x':
        case 'X':
        case 'o':
        case 'b': {
            // set the base
            unsigned int base;
            if (*format == 'x' || *format == 'X') {
                base = 16U;
            }
            else if (*format == 'o') {
                base = 8U;
            }
            else if (*format == 'b') {
                base = 2U;
            }
            else {
                base = 10U;
                flags &= ~FLAGS_HASH;   // no hash for dec format
            }
            // uppercase
            if (*format == 'X') {
                flags |= FLAGS_UPPERCASE;
            }

            // no plus or space flag for u, x, X, o, b
            if ((*format != 'i') && (*format != 'd')) {
                flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
            }

            // ignore '0' flag when precision is given
            if (flags & FLAGS_PRECISION) {
                flags &= ~FLAGS_ZEROPAD;
            }

            // convert the integer
            if ((*format == 'i') || (*format == 'd')) {
                // signed
                if (flags & FLAGS_LONG_LONG) {
#if defined(PRINTF_SUPPORT_LONG_LONG)
                    const long long value = va_arg(va, long long);
                    idx = _ntoa_long_long(out, buffer, idx, maxlen, (unsigned long long)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
#endif
                }
                else if (flags & FLAGS_LONG) {
                    const long value = va_arg(va, long);
                    idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned long)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
                }
                else {
                    const int value = (flags & FLAGS_CHAR) ? (char)va_arg(va, int) : (flags & FLAGS_SHORT) ? (short int)va_arg(va, int) : va_arg(va, int);
                    idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned int)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
                }
            }
            else {
                // unsigned
                if (flags & FLAGS_LONG_LONG) {
#if defined(PRINTF_SUPPORT_LONG_LONG)
                    idx = _ntoa_long_long(out, buffer, idx, maxlen, va_arg(va, unsigned long long), false, base, precision, width, flags);
#endif
                }
                else if (flags & FLAGS_LONG) {
                    idx = _ntoa_long(out, buffer, idx, maxlen, va_arg(va, unsigned long), false, base, precision, width, flags);
                }
                else {
                    const unsigned int value = (flags & FLAGS_CHAR) ? (unsigned char)va_arg(va, unsigned int) : (flags & FLAGS_SHORT) ? (unsigned short int)va_arg(va, unsigned int) : va_arg(va, unsigned int);
                    idx = _ntoa_long(out, buffer, idx, maxlen, value, false, base, precision, width, flags);
                }
            }
            format++;
            break;
        }
#if defined(PRINTF_SUPPORT_FLOAT)
        case 'f':
        case 'F':
            if (*format == 'F') flags |= FLAGS_UPPERCASE;
            idx = _ftoa(out, buffer, idx, maxlen, va_arg(va, double), precision, width, flags);
            format++;
            break;
#if defined(PRINTF_SUPPORT_EXPONENTIAL)
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if ((*format == 'g') || (*format == 'G')) flags |= FLAGS_ADAPT_EXP;
            if ((*format == 'E') || (*format == 'G')) flags |= FLAGS_UPPERCASE;
            idx = _etoa(out, buffer, idx, maxlen, va_arg(va, double), precision, width, flags);
            format++;
            break;
#endif  // PRINTF_SUPPORT_EXPONENTIAL
#endif  // PRINTF_SUPPORT_FLOAT
        case 'c': {
            unsigned int l = 1U;
            // pre padding
            if (!(flags & FLAGS_LEFT)) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            // char output
            out((char)va_arg(va, int), buffer, idx++, maxlen);
            // post padding
            if (flags & FLAGS_LEFT) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            format++;
            break;
        }

        case 's': {
            const char* p = va_arg(va, char*);
            unsigned int l = _strnlen_s(p, precision ? precision : (size_t)-1);
            // pre padding
            if (flags & FLAGS_PRECISION) {
                l = (l < precision ? l : precision);
            }
            if (!(flags & FLAGS_LEFT)) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            // string output
            while ((*p != 0) && (!(flags & FLAGS_PRECISION) || precision--)) {
                out(*(p++), buffer, idx++, maxlen);
            }
            // post padding
            if (flags & FLAGS_LEFT) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            format++;
            break;
        }

        case 'p': {
            width = sizeof(void*) * 2U;
            flags |= FLAGS_ZEROPAD | FLAGS_UPPERCASE;
#if defined(PRINTF_SUPPORT_LONG_LONG)
            is_ll = sizeof(uintptr_t) == sizeof(long long);
            if (is_ll) {
                idx = _ntoa_long_long(out, buffer, idx, maxlen, (uintptr_t)va_arg(va, void*), false, 16U, precision, width, flags);
            }
            else {
#endif
                idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned long)((uintptr_t)va_arg(va, void*)), false, 16U, precision, width, flags);
#if defined(PRINTF_SUPPORT_LONG_LONG)
            }
#endif
            format++;
            break;
        }

        case '%':
            out('%', buffer, idx++, maxlen);
            format++;
            break;

        default:
            out(*format, buffer, idx++, maxlen);
            format++;
            break;
        }
    }

    // termination
    out((char)0, buffer, idx < maxlen ? idx : maxlen - 1U, maxlen);

    // return written chars without terminating \0
    return (int)idx;
}


///////////////////////////////////////////////////////////////////////////////

int printf_(const char* format, ...)
{
  char buffer[1];
  va_list va;
  int ret;

  va_start(va, format);
  ret = _vsnprintf(_out_char, buffer, (size_t)-1, format, va);
  va_end(va);
  return ret;
}


int sprintf_(char* buffer, const char* format, ...)
{
  va_list va;
  int ret;

  va_start(va, format);
  ret = _vsnprintf(_out_buffer, buffer, (size_t)-1, format, va);
  va_end(va);
  return ret;
}


int snprintf_(char* buffer, size_t count, const char* format, ...)
{
  va_list va;
  int ret;

  va_start(va, format);
  ret = _vsnprintf(_out_buffer, buffer, count, format, va);
  va_end(va);
  return ret;
}


int vprintf_(const char* format, va_list va)
{
  char buffer[1];
  return _vsnprintf(_out_char, buffer, (size_t)-1, format, va);
}


int vsnprintf_(char* buffer, size_t count, const char* format, va_list va)
{
  return _vsnprintf(_out_buffer, buffer, count, format, va);
}


int fctprintf(void (*out)(char character, void* arg), void* arg, const char* format, ...)
{
  va_list va;
  out_fct_wrap_type out_fct_wrap;
  int ret;

  va_start(va, format);
  out_fct_wrap.fct = out;
  out_fct_wrap.arg = arg;
  ret = _vsnprintf(_out_fct, (char*)(uintptr_t)&out_fct_wrap, (size_t)-1, format, va);
  va_end(va);
  return ret;
}

/* printf´òÓ¡×Ö·û½Ó¿Ú */

unsigned short printf_x;
unsigned short printf_y;
unsigned short printf_newline;
unsigned short printf_Str_Color;
unsigned short printf_BG_Color;

static unsigned char ASCII[] =  //ASCII×Ö¿â,×Ö·û´óÐ¡12*6

{

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*" ",0*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"",1*/

0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0x10,/*"",2*/

0x10,0x10,0x10,0x10,0x10,0x10,0x1C,0x00,0x00,0x00,0x00,0x00,/*"",3*/

0x10,0x10,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,0x00,0x00,/*"",4*/

0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,/*"",5*/

0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,/*"",6*/

0x00,0x00,0x00,0x30,0x78,0x78,0x78,0x30,0x00,0x00,0x00,0x00,/*"",7*/

0xFC,0xFC,0xFC,0xCC,0x84,0x84,0x84,0xCC,0xFC,0xFC,0xFC,0xFC,/*"",8*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"	",9*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*" ",10*/

0x00,0x1C,0x0C,0x0C,0x14,0x10,0x30,0x48,0x48,0x30,0x00,0x00,/*"",11*/

0x00,0x38,0x44,0x44,0x38,0x10,0x7C,0x10,0x10,0x10,0x00,0x00,/*"",12*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*" ",13*/

0x00,0x0C,0x34,0x2C,0x34,0x24,0x24,0x2C,0x6C,0x60,0x00,0x00,/*"",14*/

0x00,0x54,0x54,0x28,0x28,0x6C,0x28,0x28,0x54,0x54,0x00,0x00,/*"",15*/

0x10,0x10,0x10,0x10,0x10,0x10,0xFC,0x10,0x10,0x10,0x10,0x10,/*"",16*/

0x00,0x04,0x0C,0x1C,0x3C,0x7C,0x3C,0x1C,0x0C,0x04,0x00,0x00,/*"",17*/

0x00,0x10,0x38,0x10,0x10,0x10,0x10,0x10,0x38,0x10,0x00,0x00,/*"",18*/

0x00,0x28,0x28,0x28,0x28,0x28,0x28,0x00,0x28,0x28,0x00,0x00,/*"",19*/

0x00,0x3C,0x54,0x54,0x54,0x34,0x14,0x14,0x14,0x14,0x3C,0x00,/*"",20*/

0x10,0x10,0x10,0x10,0x10,0x10,0xFC,0x00,0x00,0x00,0x00,0x00,/*"",21*/

0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x10,0x10,0x10,0x10,0x10,/*"",22*/

0x10,0x10,0x10,0x10,0x10,0x10,0xF0,0x10,0x10,0x10,0x10,0x10,/*"",23*/

0x00,0x10,0x38,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,/*"",24*/

0x10,0x10,0x10,0x10,0x10,0x10,0x1C,0x10,0x10,0x10,0x10,0x10,/*"",25*/

0x00,0x00,0x00,0x00,0x08,0x7C,0x08,0x00,0x00,0x00,0x00,0x00,/*" ",26*/

0x00,0x00,0x00,0x00,0x20,0x7C,0x20,0x00,0x00,0x00,0x00,0x00,/*"",27*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"",28*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"",29*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"",30*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"",31*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*" ",32*/

0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00,0x00,/*"!",33*/

0x00,0x28,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*""",34*/

0x00,0x00,0x28,0x28,0xFC,0x28,0x50,0xFC,0x50,0x50,0x00,0x00,/*"#",35*/

0x00,0x20,0x78,0xA8,0xA0,0x60,0x30,0x28,0xA8,0xF0,0x20,0x00,/*"$",36*/

0x00,0x00,0x48,0xA8,0xB0,0x50,0x28,0x34,0x54,0x48,0x00,0x00,/*"%",37*/

0x00,0x00,0x20,0x50,0x50,0x78,0xA8,0xA8,0x90,0x6C,0x00,0x00,/*"&",38*/

0x00,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"'",39*/

0x00,0x04,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x04,0x00,/*"(",40*/

0x00,0x40,0x20,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x40,0x00,/*")",41*/

0x00,0x00,0x00,0x20,0xA8,0x70,0x70,0xA8,0x20,0x00,0x00,0x00,/*"*",42*/

0x00,0x00,0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x00,0x00,0x00,/*"+",43*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x80,/*",",44*/

0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,/*"-",45*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,/*".",46*/

0x00,0x08,0x10,0x10,0x10,0x20,0x20,0x40,0x40,0x40,0x80,0x00,/*"/",47*/

0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,0x00,/*"0",48*/

0x00,0x00,0x20,0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00,/*"1",49*/

0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x40,0x80,0xF8,0x00,0x00,/*"2",50*/

0x00,0x00,0x70,0x88,0x08,0x30,0x08,0x08,0x88,0x70,0x00,0x00,/*"3",51*/

0x00,0x00,0x10,0x30,0x50,0x50,0x90,0x78,0x10,0x18,0x00,0x00,/*"4",52*/

0x00,0x00,0xF8,0x80,0x80,0xF0,0x08,0x08,0x88,0x70,0x00,0x00,/*"5",53*/

0x00,0x00,0x70,0x90,0x80,0xF0,0x88,0x88,0x88,0x70,0x00,0x00,/*"6",54*/

0x00,0x00,0xF8,0x90,0x10,0x20,0x20,0x20,0x20,0x20,0x00,0x00,/*"7",55*/

0x00,0x00,0x70,0x88,0x88,0x70,0x88,0x88,0x88,0x70,0x00,0x00,/*"8",56*/

0x00,0x00,0x70,0x88,0x88,0x88,0x78,0x08,0x48,0x70,0x00,0x00,/*"9",57*/

0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x20,0x00,0x00,/*":",58*/

0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x20,0x20,0x00,/*";",59*/

0x00,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x00,0x00,/*"<",60*/

0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,/*"=",61*/

0x00,0x40,0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x40,0x00,0x00,/*">",62*/

0x00,0x00,0x70,0x88,0x88,0x10,0x20,0x20,0x00,0x20,0x00,0x00,/*"?",63*/

0x00,0x00,0x70,0x88,0x98,0xA8,0xA8,0xB8,0x80,0x78,0x00,0x00,/*"@",64*/

0x00,0x00,0x20,0x20,0x30,0x50,0x50,0x78,0x48,0xCC,0x00,0x00,/*"A",65*/

0x00,0x00,0xF0,0x48,0x48,0x70,0x48,0x48,0x48,0xF0,0x00,0x00,/*"B",66*/

0x00,0x00,0x78,0x88,0x80,0x80,0x80,0x80,0x88,0x70,0x00,0x00,/*"C",67*/

0x00,0x00,0xF0,0x48,0x48,0x48,0x48,0x48,0x48,0xF0,0x00,0x00,/*"D",68*/

0x00,0x00,0xF8,0x48,0x50,0x70,0x50,0x40,0x48,0xF8,0x00,0x00,/*"E",69*/

0x00,0x00,0xF8,0x48,0x50,0x70,0x50,0x40,0x40,0xE0,0x00,0x00,/*"F",70*/

0x00,0x00,0x38,0x48,0x80,0x80,0x9C,0x88,0x48,0x30,0x00,0x00,/*"G",71*/

0x00,0x00,0xCC,0x48,0x48,0x78,0x48,0x48,0x48,0xCC,0x00,0x00,/*"H",72*/

0x00,0x00,0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,/*"I",73*/

0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x90,0xE0,0x00,/*"J",74*/

0x00,0x00,0xEC,0x48,0x50,0x60,0x50,0x50,0x48,0xEC,0x00,0x00,/*"K",75*/

0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x44,0xFC,0x00,0x00,/*"L",76*/

0x00,0x00,0xD8,0xD8,0xD8,0xD8,0xA8,0xA8,0xA8,0xA8,0x00,0x00,/*"M",77*/

0x00,0x00,0xDC,0x48,0x68,0x68,0x58,0x58,0x48,0xE8,0x00,0x00,/*"N",78*/

0x00,0x00,0x70,0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00,0x00,/*"O",79*/

0x00,0x00,0xF0,0x48,0x48,0x70,0x40,0x40,0x40,0xE0,0x00,0x00,/*"P",80*/

0x00,0x00,0x70,0x88,0x88,0x88,0x88,0xE8,0x98,0x70,0x18,0x00,/*"Q",81*/

0x00,0x00,0xF0,0x48,0x48,0x70,0x50,0x48,0x48,0xEC,0x00,0x00,/*"R",82*/

0x00,0x00,0x78,0x88,0x80,0x60,0x10,0x08,0x88,0xF0,0x00,0x00,/*"S",83*/

0x00,0x00,0xF8,0xA8,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00,/*"T",84*/

0x00,0x00,0xCC,0x48,0x48,0x48,0x48,0x48,0x48,0x30,0x00,0x00,/*"U",85*/

0x00,0x00,0xCC,0x48,0x48,0x50,0x50,0x30,0x20,0x20,0x00,0x00,/*"V",86*/

0x00,0x00,0xA8,0xA8,0xA8,0x70,0x50,0x50,0x50,0x50,0x00,0x00,/*"W",87*/

0x00,0x00,0xD8,0x50,0x50,0x20,0x20,0x50,0x50,0xD8,0x00,0x00,/*"X",88*/

0x00,0x00,0xD8,0x50,0x50,0x20,0x20,0x20,0x20,0x70,0x00,0x00,/*"Y",89*/

0x00,0x00,0xF8,0x90,0x10,0x20,0x20,0x40,0x48,0xF8,0x00,0x00,/*"Z",90*/

0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x38,0x00,/*"[",91*/

0x00,0x40,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x08,0x00,0x00,/*"\",92*/

0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x00,/*"]",93*/

0x00,0x20,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"^",94*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,/*"_",95*/

0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"`",96*/

0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x38,0x48,0x3C,0x00,0x00,/*"a",97*/

0x00,0x00,0xC0,0x40,0x40,0x70,0x48,0x48,0x48,0x70,0x00,0x00,/*"b",98*/

0x00,0x00,0x00,0x00,0x00,0x38,0x48,0x40,0x40,0x38,0x00,0x00,/*"c",99*/

0x00,0x00,0x18,0x08,0x08,0x38,0x48,0x48,0x48,0x3C,0x00,0x00,/*"d",100*/

0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x78,0x40,0x38,0x00,0x00,/*"e",101*/

0x00,0x00,0x1C,0x20,0x20,0x78,0x20,0x20,0x20,0x78,0x00,0x00,/*"f",102*/

0x00,0x00,0x00,0x00,0x00,0x3C,0x48,0x30,0x40,0x78,0x44,0x38,/*"g",103*/

0x00,0x00,0xC0,0x40,0x40,0x70,0x48,0x48,0x48,0xEC,0x00,0x00,/*"h",104*/

0x00,0x00,0x20,0x00,0x00,0x60,0x20,0x20,0x20,0x70,0x00,0x00,/*"i",105*/

0x00,0x00,0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x10,0xE0,/*"j",106*/

0x00,0x00,0xC0,0x40,0x40,0x5C,0x50,0x70,0x48,0xEC,0x00,0x00,/*"k",107*/

0x00,0x00,0xE0,0x20,0x20,0x20,0x20,0x20,0x20,0xF8,0x00,0x00,/*"l",108*/

0x00,0x00,0x00,0x00,0x00,0xF0,0xA8,0xA8,0xA8,0xA8,0x00,0x00,/*"m",109*/

0x00,0x00,0x00,0x00,0x00,0xF0,0x48,0x48,0x48,0xEC,0x00,0x00,/*"n",110*/

0x00,0x00,0x00,0x00,0x00,0x30,0x48,0x48,0x48,0x30,0x00,0x00,/*"o",111*/

0x00,0x00,0x00,0x00,0x00,0xF0,0x48,0x48,0x48,0x70,0x40,0xE0,/*"p",112*/

0x00,0x00,0x00,0x00,0x00,0x38,0x48,0x48,0x48,0x38,0x08,0x1C,/*"q",113*/

0x00,0x00,0x00,0x00,0x00,0xD8,0x60,0x40,0x40,0xE0,0x00,0x00,/*"r",114*/

0x00,0x00,0x00,0x00,0x00,0x78,0x40,0x30,0x08,0x78,0x00,0x00,/*"s",115*/

0x00,0x00,0x00,0x20,0x20,0x70,0x20,0x20,0x20,0x18,0x00,0x00,/*"t",116*/

0x00,0x00,0x00,0x00,0x00,0xD8,0x48,0x48,0x48,0x3C,0x00,0x00,/*"u",117*/

0x00,0x00,0x00,0x00,0x00,0xEC,0x48,0x50,0x30,0x20,0x00,0x00,/*"v",118*/

0x00,0x00,0x00,0x00,0x00,0xA8,0xA8,0x70,0x50,0x50,0x00,0x00,/*"w",119*/

0x00,0x00,0x00,0x00,0x00,0xD8,0x50,0x20,0x50,0xD8,0x00,0x00,/*"x",120*/

0x00,0x00,0x00,0x00,0x00,0xEC,0x48,0x50,0x30,0x20,0x20,0xC0,/*"y",121*/

0x00,0x00,0x00,0x00,0x00,0x78,0x10,0x20,0x20,0x78,0x00,0x00,/*"z",122*/

0x00,0x18,0x10,0x10,0x10,0x20,0x10,0x10,0x10,0x10,0x18,0x00,/*"{",123*/

0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,/*"|",124*/

0x00,0x60,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x60,0x00,/*"}",125*/

0x40,0xA4,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"~",126*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00/*"",127*/

};

#define DrawPixel \
    if (b > (unsigned char)127) { \
        Lcd_WriteData_16Bit_V(printf_Str_Color); \
    } else { \
        Lcd_WriteData_16Bit_V(printf_BG_Color); \
    }

void _putchar(char character) {
    static unsigned short start_x;

    if (character != '\n') {
        unsigned char i;
        unsigned char* p = &ASCII[(unsigned short)character * 12];

        if (printf_newline != (unsigned char)0) {
            printf_newline = 0;
            start_x = printf_x;
        }
        Lcd_SetRegion(printf_x, printf_x + 5, printf_y, printf_y + 11);
        Lcd_WriteIndex(0x2c);
        for (i = 0; i < 12; ++i) {
            unsigned char b = *p++;

            DrawPixel; b <<= 1;
            DrawPixel; b <<= 1;
            DrawPixel; b <<= 1;
            DrawPixel; b <<= 1;
            DrawPixel; b <<= 1;
            DrawPixel;
        }
        printf_x += 6;
    } else {
        printf_x = start_x;
        printf_y += 12;
        printf_newline = 1;
    }
}
