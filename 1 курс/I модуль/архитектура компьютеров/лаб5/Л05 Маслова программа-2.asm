%include 'in_out.asm'

SECTION .data
msg1: DB 'Введите х:',0
msg2: DB 'Введите а:',0
div: DB 'Результат:',0

SECTION .bss
x: RESB 80
a: RESB 80
rez: RESB 80

SECTION .text
GLOBAL _start

_start:
    ;ввод х
    mov eax,msg1
    call sprintLF

    mov ecx,x
    mov edx,80
    call sread

    mov eax,x
    call atoi
    mov [x],eax

    ;ввод а
    mov eax,msg2
    call sprintLF

    mov ecx,a
    mov edx,80
    call sread

    mov ebx,a
    call atoi
    mov [a],ebx

    ;начало сравнения
    cmp eax,4
    jl less
    jmp greaterequal

less:
    mov eax,[x]
    add eax,4
    mov eax,rez
    call atoi
    mov [rez],eax
    jmp fin

greaterequal:
    mov [a],ebx
    mov eax,[x]
    mul ebx
    mov eax,rez
    call atoi
    mov [rez],eax
    jmp fin

fin:
    mov eax,div
    call sprint
    mov eax,[rez]
    call iprintLF
    call quit


























