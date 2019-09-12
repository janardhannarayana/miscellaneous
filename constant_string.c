#include <stdio.h>

int main()
{
    char *ptr = "Janardhan"; // stored in .rodata segment
    printf("ptr = %s\n",ptr);
    return 0;
}


/*
 * Verification process
 * Compile with gcc -g
 */
/*
janardhan-vm@miscellaneous$gcc -g constant_string.c
janardhan-vm@miscellaneous$gdb ./a.out
GNU gdb (Ubuntu 7.11.1-0ubuntu1~16.5) 7.11.1
Copyright (C) 2016 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    Reading symbols from ./a.out...done.
    (gdb) b main
    Breakpoint 1 at 0x40052e: file constant_string.c, line 5.
    (gdb) r
    Starting program: /home/janardhan/test/GIT/miscellaneous/a.out
    warning: the debug information found in "/lib64/ld-2.23.so" does not match "/lib64/ld-linux-x86-64.so.2" (CRC mismatch).


    Breakpoint 1, main () at constant_string.c:5
							   5           char *ptr = "Janardhan"; // stored in .rodata segment
(gdb) n
6           printf("ptr = %s\n",ptr);
(gdb) print ptr
$1 = 0x4005e4 "Janardhan"
    (gdb) info files
    Symbols from "/home/janardhan/test/GIT/miscellaneous/a.out".
    Native process:
            Using the running image of child process 26219.
    While running this, GDB does not access memory from...
    Local exec file:
            `/home/janardhan/test/GIT/miscellaneous/a.out', file type elf64-x86-64.
        Entry point: 0x400430
        0x0000000000400238 - 0x0000000000400254 is .interp
        0x0000000000400254 - 0x0000000000400274 is .note.ABI-tag
        0x0000000000400274 - 0x0000000000400298 is .note.gnu.build-id
        0x0000000000400298 - 0x00000000004002b4 is .gnu.hash
        0x00000000004002b8 - 0x0000000000400318 is .dynsym
        0x0000000000400318 - 0x0000000000400357 is .dynstr
        0x0000000000400358 - 0x0000000000400360 is .gnu.version
        0x0000000000400360 - 0x0000000000400380 is .gnu.version_r
        0x0000000000400380 - 0x0000000000400398 is .rela.dyn
        0x0000000000400398 - 0x00000000004003c8 is .rela.plt
        0x00000000004003c8 - 0x00000000004003e2 is .init
        0x00000000004003f0 - 0x0000000000400420 is .plt
        0x0000000000400420 - 0x0000000000400428 is .plt.got
        0x0000000000400430 - 0x00000000004005d2 is .text
        0x00000000004005d4 - 0x00000000004005dd is .fini
        0x00000000004005e0 - 0x00000000004005f8 is .rodata
        0x00000000004005f8 - 0x000000000040062c is .eh_frame_hdr
        0x0000000000400630 - 0x0000000000400724 is .eh_frame
        0x0000000000600e10 - 0x0000000000600e18 is .init_array
        0x0000000000600e18 - 0x0000000000600e20 is .fini_array
        0x0000000000600e20 - 0x0000000000600e28 is .jcr
        0x0000000000600e28 - 0x0000000000600ff8 is .dynamic
        0x0000000000600ff8 - 0x0000000000601000 is .got
        0x0000000000601000 - 0x0000000000601028 is .got.plt
        0x0000000000601028 - 0x0000000000601038 is .data
        0x0000000000601038 - 0x0000000000601040 is .bss
*/

/*
 * ptr contains address 0x4005e4
 * from gdb 0x4005e4 lies in         0x00000000004005e0 - 0x00000000004005f8 is .rodata
 */
