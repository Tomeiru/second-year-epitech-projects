BITS 64
SECTION .text
GLOBAL strcspn

strcspn:
        MOV R10, RDI
        MOV R8, RSI
        MOV RAX, 0

first_loop:
        JMP second_loop
        CMP BYTE[R10], 0
        JE end

second_loop:
        MOV R9B, BYTE[R10]
        CMP BYTE[R8], R9B
        JE end
        CMP BYTE[R8], 0
        JE incr
        ADD R8, 1
        JMP second_loop

incr:
        ADD RAX, 1

reset:
        MOV R8, RSI
        ADD R10, 1
        JMP first_loop

end:
        RET
