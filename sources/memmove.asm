BITS 64
SECTION .text
GLOBAL memmove

memmove:
        XOR R9, R9
        XOR R10, R10

loop:
        CMP R9, RDX
        JE second_loop
        MOV R11B, BYTE[RSI + R9]
        MOV BYTE[RBP + R9], R11B
        ADD R9, 1
        JMP loop

second_loop:
        CMP R10, RDX
        JE end
        MOV R11B, BYTE[RBP + R10]
        MOV BYTE[RDI + R10], R11B
        ADD R10, 1
        JMP second_loop

end:
        MOV RAX, RDI
        RET
