/* multiboot header constants */
.set ALIGN,   1<<0
.set MEMINFO, 1<<1
.set FLAGS,   ALIGN | MEMINFO
.set MAGIC,   0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)


/* multiboot header that marks the kernel as multiboot-compliant  */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM



/* 
reserve 16KB for the kernel's initial stack, 16-byte aligned
to comply within the system V ABI standard 
*/
.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:



/* kernel entrypoint */
.section .text
.global _start
.type _start, @function
_start:
        movl $stack_top, %esp  /* initialize ESP so that the kernel has a valid stack before calling C code */


        call _init  /* run CRT initialization routine */
        call kernel_main  /* transfer control to C (kernel_main) */


        /*
        if kernel_main returns, disable interrupts (cli), 
        and halt the processor forever.
        */
        cli
1:      hlt
        jmp 1b


.size _start, . - _start