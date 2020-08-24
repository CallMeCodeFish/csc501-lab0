/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <lab0.h>
#include <proc.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	int start = get_ctr1000();
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE) {
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_SCOUNT] += 1;
			time_execution[currpid][IDX_SCOUNT] += duration;
		}
		return(SYSERR);
	}
		

	if (is_tracing) {
		int duration = get_ctr1000() - start;
		is_process_executed[currpid] = 1;
		num_execution[currpid][IDX_SCOUNT] += 1;
		time_execution[currpid][IDX_SCOUNT] += duration;
	}

	return(semaph[sem].semcnt);
}
