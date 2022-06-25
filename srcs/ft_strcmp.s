            global  ft_strcmp

            section .text

ft_strcmp:  mov     rcx, 0

loop:       mov     bl, byte [rdi + rcx]
            cmp     bl, byte [rsi + rcx]
            jg      pos
            jl      neg
            cmp     byte [rdi + rcx], 0
            je      equ
            inc     rcx
            jmp     loop

pos:        mov     rax, 1
            ret

neg:        mov     rax, -1
            ret

equ:        mov     rax, 0
            ret
