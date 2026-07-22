.section .init
.global _init
.type _init, @function
        push %ebp
        movl %esp, %ebp


.section .fini
.global _fini
.type _fini, @function
        push %ebp
        movl %esp, %ebp