BITS 64
SECTION .text
GLOBAL memmove

memmove:
        XOR RAX, RAX
        XOR R9, R9

loop:
        CMP R9, RDX
        JE second_loop
        MOV AL, BYTE[RSI + R9]
        PUSH RAX
        ADD R9, 1
        JMP loop

second_loop:
        CMP R9, 0
        JE end
        SUB R9, 1
        POP RAX
        MOV BYTE[RDI + R9], AL
        JMP second_loop

end:
        MOV RAX, RDI
        RET