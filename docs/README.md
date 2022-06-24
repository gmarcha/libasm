# How to deal with assembly ?

1. Install `nasm` (see `./scripts/install.sh`).
2. Write an assembly source file with Intel convention (`.s` files).
3. Assemble it with `nasm -f elf64` (see `./scripts/assemble.sh`).

## Useful links.

- [Tutorial](https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm) on assembly programming.
- Short [tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/) on `elf64` assembly.
- [NASM](https://www.nasm.us/xdoc/2.15.05/html/nasmdoc0.html) documentation.
- A short [cheat-sheet](https://gist.github.com/justinian/385c70347db8aca7ba93e87db90fc9a6) on x64 NASM.
- [List](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/) of system calls in linux.
- Using [loops](https://stackoverflow.com/questions/28665528/while-do-while-for-loops-in-assembly-language-emu8086) with conditional jumps.
