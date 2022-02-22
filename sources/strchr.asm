BITS 64
SECTION .text
GLOBAL strchr

strchr:
        MOV RAX, RDI

loop:
        CMP BYTE[RAX], 0
        JE endalt
        CMP BYTE[RAX], SIL
        JE end
        ADD RAX, 1
        JMP loop

end:
        RET

endalt:
        MOV RAX, 0
        RET
