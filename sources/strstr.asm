BITS 64
SECTION .text
GLOBAL strstr

strstr:
        MOV RAX, RDI
        MOV R8, RSI
        MOV R9, 0

loop:
        CMP BYTE[RAX], 0
        JE endalt
        JMP second_loop


second_loop:
        CMP BYTE[R8], 0
        JE end
        MOV R10B, BYTE[RAX + R9]
        CMP BYTE[R8], R10B
        JE incr
        JMP reset

reset:
        MOV R8, RSI
        MOV R9, 0
        ADD RAX, 1
        JMP loop

incr:
        ADD R9, 1
        ADD R8, 1
        JMP second_loop

end:
        RET

endalt:
        MOV RAX, 0
        RET