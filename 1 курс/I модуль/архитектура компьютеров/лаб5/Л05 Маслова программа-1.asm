%include 'in_out.asm'
section .data
    msg1 db 'Введите В:',0h
    msg2 db 'Наименьшее число:',0h
    A dd '17'
    C dd '44'

segment .bss
    min resb 10
    B resb 10

section .text
    global _start

_start:
    mov eax,msg1
    call sprint

    mov ecx,B
    mov edx,10
    call sread

    mov eax,B
    call atoi
    mov [B],eax

    mov ecx,[A]
    mov [min],ecx

    cmp ecx,[C]
    jl check_B
    mov ecx,[C]
    mov [min],ecx

check_B:
    cmp ecx,[B]
    jl fin
    mov ecx,[B]
    mov [min],ecx

fin:
    mov eax,msg2
    call sprint
    mov eax,[min]
    call iprintLF
    call quit