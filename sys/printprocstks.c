#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

static unsigned long *esp;

void printprocstks(int priority) {
    kprintf("void printprocstks(int priority)\n");

    int i;
    for (i = 0; i < NPROC; i++) {
        struct pentry proc = proctab[i];
        if (proc.pprio > priority && proc.pstate != PRFREE) {
            kprintf("Process [%s]\n", proc.pname);
            kprintf("\tpid: %d\n", i);
            kprintf("\tpriority: %d\n", proc.pprio);
            kprintf("\tbase: 0x%08x\n", proc.pbase);
            kprintf("\tlimit: 0x%08x\n", proc.plimit);
            kprintf("\tlen: %d\n", proc.pstklen);
            if (currpid == i) {
                asm("movl %esp, esp");
                kprintf("\tpointer: 0x%08x\n", esp);
            } else {
                kprintf("\tpointer: 0x%08x\n", proc.pesp);
            }
        }
    }

}