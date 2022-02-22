BITS 64
SECTION .text
GLOBAL strrchr

strrchr:
        MOV R9, RDI
        MOV R10, 0

loop:
        CMP BYTE[R9], 0
        JE end
        CMP BYTE[R9], SIL
        JE define

endloop:
        ADD R9, 1
        JMP loop

end:
        CMP R10, 0
        JE endalt
        RET

endalt:
        MOV RAX, 0
        RET

define:
        MOV RAX, R9
        MOV R10, 1
        JMP endloop
