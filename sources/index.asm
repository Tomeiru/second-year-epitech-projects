BITS 64
SECTION .text
GLOBAL index

index:
        MOV RAX, RDI

loop:
        CMP BYTE[RAX], SIL
        JE end
        CMP BYTE[RAX], 0
        JE endalt
        ADD RAX, 1
        JMP loop

end:
        RET

endalt:
        MOV RAX, 0
        RET
