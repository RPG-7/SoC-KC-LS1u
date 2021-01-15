BIT_LEN = 4
OPERATIONS = [
    #S M Ci F
    (0x0, 0, 0, lambda a, b: a),
    (0x0, 0, 1, lambda a, b: a + 1),
    (0x0, 1, 0, lambda a, b: ~a),
    (0x1, 0, 0, lambda a, b: (a | b)),
    (0x1, 0, 1, lambda a, b: (a | b) + 1),
    (0x1, 1, 0, lambda a, b: ~(a | b)),
    (0x2, 0, 0, lambda a, b: (a | ~b)),
    (0x2, 0, 1, lambda a, b: (a | ~b) + 1),
    (0x2, 1, 0, lambda a, b: (~a) & b),
    (0x3, 0, 0, lambda a, b: -1),
    (0x3, 0, 1, lambda a, b: 0),
    (0x3, 1, 0, lambda a, b: 0),
    (0x4, 0, 0, lambda a, b: a + (a & ~b)),
    (0x4, 0, 1, lambda a, b: a + (a & ~b) + 1),
    (0x4, 1, 0, lambda a, b: ~(a & b)),
    (0x5, 0, 0, lambda a, b: (a | b) + (a & ~ b)),
    (0x5, 0, 1, lambda a, b: (a | b) + (a & ~ b) + 1),
    (0x5, 1, 0, lambda a, b: ~ b),
    (0x6, 0, 0, lambda a, b: (a - b) - 1),
    (0x6, 0, 1, lambda a, b: (a - b)),
    (0x6, 1, 0, lambda a, b: (a ^ b)),
    (0x7, 0, 0, lambda a, b: (a & ~b) - 1),
    (0x7, 0, 1, lambda a, b: (a & ~b)),
    (0x7, 1, 0, lambda a, b: (a & ~b)),
    (0x8, 0, 0, lambda a, b: a + (a & b)),
    (0x8, 0, 1, lambda a, b: a + (a & b) + 1),
    (0x8, 1, 0, lambda a, b: (~a | b)),
    (0x9, 0, 0, lambda a, b: a + b),
    (0x9, 0, 1, lambda a, b: a + b + 1),
    (0x9, 1, 0, lambda a, b: ~(a ^ b)),
    (0xa, 0, 0, lambda a, b: (a | ~b) + (a & b)),
    (0xa, 0, 1, lambda a, b: (a | ~b) + (a & b) + 1),
    (0xa, 1, 0, lambda a, b: b),
    (0xb, 0, 0, lambda a, b: (a & b) - 1),
    (0xb, 0, 1, lambda a, b: a & b),
    (0xb, 1, 0, lambda a, b: a & b),
    (0xc, 0, 0, lambda a, b: a + a),
    (0xc, 0, 1, lambda a, b: a + a + 1),
    (0xc, 1, 0, lambda a, b: 0xF),
    (0xd, 0, 0, lambda a, b: (a | b) + a),
    (0xd, 0, 1, lambda a, b: (a | b) + a + 1),
    (0xd, 1, 0, lambda a, b: a | ~b),
    (0xe, 0, 0, lambda a, b: (a | ~b) + a),
    (0xe, 0, 1, lambda a, b: (a | ~b) + a + 1),
    (0xe, 1, 0, lambda a, b: (a | b)),
    (0xf, 0, 0, lambda a, b: a - 1),
    (0xf, 0, 1, lambda a, b: a),
    (0xf, 1, 0, lambda a, b: a),
]

def build_bitmask():
    bitmask = 0
    for i in range(0, BIT_LEN):
        bitmask = bitmask | (1 << i)
    return bitmask

def main():
    bitmask = build_bitmask()
    with open("74181.tv", "w") as tv_f:
        for operation in OPERATIONS:
            for op_a in range(0, 2**BIT_LEN):
                for op_b in range(0, 2**BIT_LEN):
                    tv_f.write('{0:04b}{1:b}{2:b}{3:04b}{4:04b}{5:04b}\n'.format(
                        operation[0],
                        operation[1],
                        operation[2],
                        op_a,
                        op_b,
                        operation[3](op_a, op_b) & bitmask))
        tv_f.write("xxxx")

if __name__ == '__main__':
    main()
