%include 'in_out.asm'

SECTION .data
    msg1 db 'Результат: ',0h

SECTION .bss
    N: resb 10

SECTION .text
    global _start

_start:
    mov eax,msg1
    call sprint
    pop ecx
    pop edx
    sub ecx,1

next:
    cmp ecx,0h
    jz _end

    pop eax
    call atoi_
    mov [N],eax

    push    eax
    push    ecx
    push    edx
    push    esi

    mov eax,4
    mov ebx,1
    mov ecx,N
    mov edx,10
    int 80h

    pop     esi
    pop     edx
    pop     ecx
    pop     eax

    loop next
_end:
    call quit


atoi_:
    push    ebx
    push    ecx
    push    edx
    push    esi
    mov     esi, eax
    mov     eax, 0
    mov     ecx, 0

.multiplyLoop:
    xor     ebx, ebx
    mov     bl, [esi+ecx]
    cmp     bl, 48
    jl      .finished
    cmp     bl, 57
    jg      .finished
 
    sub     bl, 48
    add     eax, ebx
    mov     ebx,9
    mul     ebx
    inc     ecx
    jmp     .multiplyLoop

.finished:
    cmp     ecx, 0
    je      .restore
    mov     ebx, 9
    div     ebx

.restore:
    pop     esi
    pop     edx
    pop     ecx
    pop     ebx
    ret
