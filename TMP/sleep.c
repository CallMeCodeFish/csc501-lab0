/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	int start = get_ctr1000();

	STATWORD ps;    
	if (n<0 || clkruns==0) {
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_SLEEP] += 1;
			time_execution[currpid][IDX_SLEEP] += duration;
		}
		return(SYSERR);
	}
		
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		if (is_tracing) {
			int duration = get_ctr1000() - start;
			is_process_executed[currpid] = 1;
			num_execution[currpid][IDX_SLEEP] += 1;
			time_execution[currpid][IDX_SLEEP] += duration;
		}
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);

	if (is_tracing) {
		int duration = get_ctr1000() - start;
		is_process_executed[currpid] = 1;
		num_execution[currpid][IDX_SLEEP] += 1;
		time_execution[currpid][IDX_SLEEP] += duration;
	}

	return(OK);
}
