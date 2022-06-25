            global  _start

            section .text
_start:     mov     rax, 1
            mov     rdi, 42
            mov     rsi, msg
            mov     rdx, 4
            syscall

            mov rdi, rax
            mov rax, 60
            syscall

            section .rodata
msg:        db      "Hey!", 10