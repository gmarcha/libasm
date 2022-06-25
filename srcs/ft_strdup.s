            global  ft_strdup
            extern  malloc
            extern  ft_strlen
            extern  ft_strcpy

            section .text
ft_strdup:  mov     r12, rdi
            call    ft_strlen
            mov     rbx, rax
            mov     rdi, rax
            inc     rdi
            call    malloc
            cmp     rax, 0
            je      end
            mov     byte [rax + rbx], 0
            mov     rdi, rax
            mov     rsi, r12
            call    ft_strcpy
end:        ret
