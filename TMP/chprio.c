/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	int start = get_ctr1000();

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_CHPRIO] += 1;
			time_execution[currpid][IDX_CHPRIO] += duration;
		}
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);

	if (is_tracing) {
		int duration = get_ctr1000() - start;
		is_process_executed[currpid] = 1;
		num_execution[currpid][IDX_CHPRIO] += 1;
		time_execution[currpid][IDX_CHPRIO] += duration;
	}

	return(newprio);
}
