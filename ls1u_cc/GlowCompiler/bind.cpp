#include "c.h"

#undef yy
#define yy \
xx(sparc/sun,    _sparcIR) \
xx(sparc/solaris,solarisIR) \
xx(symbolic/osf, symbolic64IR) \
xx(symbolic/irix,symbolicIR) \
xx(symbolic,     symbolicIR) \
xx(bytecode,     bytecodeIR) \
xx(null,         nullIR) \
xx(glow,         glowIR)

#undef xx
#define xx(a,b) extern _Interface b;
yy

Binding bindings[] = {
	
#undef xx
#define xx(a,b) #a, &b,
yy
	NULL, NULL
	
};

#undef yy
#undef xx
