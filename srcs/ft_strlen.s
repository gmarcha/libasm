            global  ft_strlen

            section .text
ft_strlen:  mov     rax, 0                  ; or xor rax, rax (both reset register)
            jmp     loop

cloop:      inc     rax
loop:       cmp     byte [rdi + rax], 0
            jne     cloop
            ret