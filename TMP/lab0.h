#ifndef _P0_H_
#define _P0_H_


#define IDX_FREEMEM     0
#define IDX_CHPRIO      1
#define IDX_GETPID      2
#define IDX_GETPRIO     3
#define IDX_GETTIME     4
#define IDX_KILL        5
#define IDX_RECEIVE     6
#define IDX_RECVCLR     7
#define IDX_RECVTIM     8
#define IDX_RESUME      9
#define IDX_SCOUNT      10
#define IDX_SDELETE     11
#define IDX_SEND        12
#define IDX_SETDEV      13
#define IDX_SETNOK      14
#define IDX_SCREATE     15
#define IDX_SIGNAL      16
#define IDX_SIGNALN     17
#define IDX_SLEEP       18
#define IDX_SLEEP10     19
#define IDX_SLEEP100    20
#define IDX_SLEEP1000   21
#define IDX_SRESET      22
#define IDX_STACKTRACE  23
#define IDX_SUSPEND     24
#define IDX_UNSLEEP     25
#define IDX_WAIT        26

#define NUM_DEFINED_SYSCALL             27
#define SYSCALL_NAME_MAX_LENGTH         20
#define NPROC                           50


int num_execution[NPROC][NUM_DEFINED_SYSCALL];
int time_execution[NPROC][NUM_DEFINED_SYSCALL];
int is_process_executed[NPROC];
int is_tracing;


long zfunction(long param);

void printsegaddress();

void printtos();

void printprocstks(int priority);

void printsyscallsummary();

void syscallsummary_start();

void syscallsummary_stop();

int get_ctr1000();


#endif
