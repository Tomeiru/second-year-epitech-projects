BITS 64
SECTION .text
GLOBAL memcpy

memcpy:
        MOV RAX, RDI
        XOR R9, R9
        XOR R10B, R10B

copy_temp:
        CMP RDX, R9
        JE end
        MOV R10B, BYTE[RSI + R9]
        MOV BYTE [RDI + R9], R10B
        INC R9
        JMP copy_temp

end:
        RET
