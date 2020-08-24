/* send.c - send */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  send  --  send a message to another process
 *------------------------------------------------------------------------
 */
SYSCALL	send(int pid, WORD msg)
{
	int start = get_ctr1000();

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || ( (pptr= &proctab[pid])->pstate == PRFREE)
	   || pptr->phasmsg != 0) {
		restore(ps);
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_SEND] += 1;
			time_execution[currpid][IDX_SEND] += duration;
		}
		return(SYSERR);
	}
	pptr->pmsg = msg;
	pptr->phasmsg = TRUE;
	if (pptr->pstate == PRRECV)	/* if receiver waits, start it	*/
		ready(pid, RESCHYES);
	else if (pptr->pstate == PRTRECV) {
		unsleep(pid);
		ready(pid, RESCHYES);
	}
	restore(ps);

	if (is_tracing) {
		int duration = get_ctr1000() - start;
		is_process_executed[currpid] = 1;
		num_execution[currpid][IDX_SEND] += 1;
		time_execution[currpid][IDX_SEND] += duration;
	}

	return(OK);
}
