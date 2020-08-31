/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

int prX;
void halt();

prch(c)
char c;
{
	int i;
	sleep(1);	
	sleep(1);	
}


int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");

	kprintf("\n=================== Task 1 ===================\n");
	
	long value = zfunction(0xaabbccdd);
	kprintf("zfunction(0xaabbccdd) = 0x%08X\n", value);

	kprintf("\n=================== Task 2 ===================\n");

	printsegaddress();

	kprintf("\n=================== Task 3 ===================\n");
	printtos();

	kprintf("\n=================== Task 4 ===================\n");
	printprocstks(9);

	kprintf("\n=================== Task 5 ===================\n");
	syscallsummary_start();        
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	sleep(10);
	syscallsummary_stop();
	printsyscallsummary();

	return 0;
}
