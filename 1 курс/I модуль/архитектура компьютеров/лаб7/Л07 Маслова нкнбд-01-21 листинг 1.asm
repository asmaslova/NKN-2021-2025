%include 'in_out1.asm'

SECTION .data
    msg1 db 'Введите число: ',0h
    msg2 db 'Результат: ',0h

SECTION .bss
    N: resb 10

SECTION .text
    global _start

_start:
    mov eax,msg1
    call sprint
    mov ecx,N
    mov edx,10
    call sread
    mov eax,N
    call atoi
    mov eax,msg2
    call sprint
    mov [N],eax
    call iprintLF
    call quit