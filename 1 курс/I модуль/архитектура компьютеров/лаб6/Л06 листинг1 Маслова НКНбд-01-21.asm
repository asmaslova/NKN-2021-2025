%include 'in_out.asm'

SECTION .data
    msg1 db 'Введите N: ',0h
    msg2 db 'Результат: ',0h

SECTION .bss
    N: resb 10
    Sum: resb 10

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
    mov [N],eax

    mov ecx,[N]
    mov eax,1

label:
    mul ecx
    loop label

    mov [Sum],eax
    mov eax,msg2
    call sprint
    mov eax,[Sum]
    call iprintLF

call quit