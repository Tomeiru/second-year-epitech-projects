BITS 64
SECTION .text
GLOBAL memset

memset:
        MOV RAX, RDI
        MOV R10, RDX

loop:
        CMP R10, 0
        JE end
        MOV BYTE[RAX], SIL
        ADD RAX, 1
        SUB R10, 1
        JMP loop

end:
    MOV RAX, RDI
    RET