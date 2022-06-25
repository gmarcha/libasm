            global  ft_strcpy

            section .text
ft_strcpy:  mov     rcx, 0
            jmp     loop

cloop:      mov     bl, byte [rsi + rcx]
            mov     byte [rdi + rcx], bl
            inc     rcx

loop:       cmp     byte [rsi + rcx], 0
            jne     cloop
            mov     rax, rdi
            ret
