BITS 64
SECTION .text
GLOBAL strpbrk

strpbrk:
        MOV RAX, RDI
        MOV R8, RSI

first_loop:
        CMP BYTE[RAX], 0
        JE end
        JMP second_loop

second_loop:
        MOV R9B, BYTE[RAX]
        CMP BYTE[R8], R9B
        JE end
        CMP BYTE[R8], 0
        JE incr
        ADD R8, 1
        JMP second_loop

incr:
        MOV R8, RSI
        ADD RAX, 1
        JMP first_loop

end:
        RET

endalt:
        MOV RAX, 0
        RET
