#! /bin/bash

nasm -f elf64 -o docs/hello.o docs/hellox64.s

# -f: output object file format
# -o: output object file name

ld -o docs/hello.out docs/hello.o
