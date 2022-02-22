BITS 64
SECTION .text
GLOBAL strcasecmp

strcasecmp:
        MOV RAX, 0

loop:
        MOV R9B, BYTE[RSI]
        CMP R9B, 0x5B
        JL check_one_maj

mid_loop:
        MOV R10B, BYTE[RDI]
        CMP R10B, 0x5B
        JL check_two_maj

end_loop:
        CMP BYTE[RDI], 0
        JE end
        CMP R10B, R9B
        JNE end
        ADD RDI, 1
        ADD RSI, 1
        JMP loop

check_one_maj:
        CMP R9B, 0x40
        JA check_final_maj
        JMP mid_loop

check_final_maj:
        ADD R9B, 0x20
        JMP mid_loop

check_two_maj:
        CMP R10B, 0x40
        JA check_final_maj_sec
        JMP end_loop

check_final_maj_sec:
        ADD R10B, 0x20
        JMP end_loop

end:
        MOVZX RAX, R10B
        MOVZX RBX, R9B
        SUB RAX, RBX
        RET
