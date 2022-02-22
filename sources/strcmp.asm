BITS 64
SECTION .text
GLOBAL strcmp

strcmp:
        MOV RAX, 0

loop:
        CMP BYTE[RDI], 0
        JE end
        MOV CH, BYTE[RSI]
        CMP BYTE[RDI], CH
        JNE end
        ADD RDI, 1
        ADD RSI, 1
        JMP loop

end:
        MOVZX RAX, BYTE[RDI]
        MOVZX RBX, BYTE[RSI]
        SUB RAX, RBX
        RET
