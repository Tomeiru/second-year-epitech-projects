BITS 64
SECTION .text
GLOBAL strlen

strlen:
        MOV RAX, 0
        MOV R9, RDI

loop:
        CMP BYTE[R9], 0
        JE end
        ADD RAX, 1
        ADD R9, 1
        JMP loop

end:
    RET