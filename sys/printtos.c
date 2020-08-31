#include <kernel.h>
#include <stdio.h>
#include <proc.h>
#include <lab0.h>

static unsigned long *esp;
static unsigned long *ebp;



void printtos() {
    kprintf("void printtos()\n");
    asm("movl %ebp, ebp");
    asm("movl %esp, esp");

    kprintf("Before[0x%08x]: 0x%08x\n", ebp + 2, *(ebp + 2));
    kprintf("After[0x%08x]: 0x%08x\n", ebp, *ebp);
    
    int i;
    for (i = 1; i <= 4 && esp + i <= ebp; i++) {
        kprintf("\telement[0x%08x]: 0x%08x\n", esp + i, *(esp + i));
    }
}