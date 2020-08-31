/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	int start = get_ctr1000();

	short	*nxtdev;

	if (isbadpid(pid)) {
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_SETDEV] += 1;
			time_execution[currpid][IDX_SETDEV] += duration;
		}
		return(SYSERR);
	}
		
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;

	if (is_tracing) {
		int duration = get_ctr1000() - start;
		is_process_executed[currpid] = 1;
		num_execution[currpid][IDX_SETDEV] += 1;
		time_execution[currpid][IDX_SETDEV] += duration;
	}
	
	return(OK);
}
