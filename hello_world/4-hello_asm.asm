section .data                   ; data section
                                ; the string to print, 0xa=cr
msg:    db "Hello, asm", 0xa
len     equ $-msg               ; $ means "here"
                                ; len is a value, not an address

section .text                   ; code section
global main                     ; make label available to linker

main:                           ; standard gcc entry point
        mov     edx, len        ; arg3, length of string to print
        mov     ecx, msg        ; arg2, address of the string
        mov     ebx, 2          ; arg1, where to write, standard error
        mov     eax, 4          ; system call number (sys_write)
        int     0x80            ; interrupt 80 hex, call kernel

        mov     ebx, 0          ; exit code, 0=normal
        mov     eax, 1          ; system call number (sys_exit)
        int     0x80            ; interrupt 80 hex, call kernel