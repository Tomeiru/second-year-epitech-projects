BITS 64
SECTION .text
GLOBAL my_memmove

my_memmove:
        XOR RAX, RAX
        XOR R9, R9
        XOR R10B, R10B

loop:
        CMP R9, RDX
        JE intermediate
        MOV AL, BYTE[RSI + R9]
        PUSH RAX
        ADD R9, 1
        JMP loop

intermediate:
        SUB R9, 1

second_loop:
        CMP R9, -1
        JE end
        POP RAX
        MOV BYTE[RDI + R9], AL
        SUB R9, 1
        JMP second_loop

end:
        RET
