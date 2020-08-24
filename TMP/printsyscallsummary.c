#include <lab0.h>
#include <stdio.h>

char syscall_name[NUM_DEFINED_SYSCALL][SYSCALL_NAME_MAX_LENGTH] = {"freemem", "chprio", "getpid", "getprio",
                                                                   "gettime", "kill", "receive", "recvclr",
                                                                   "recvtim", "resume", "scount", "sdelete",
                                                                   "send", "setdev", "setnok", "screate",
                                                                   "signal", "signaln", "sleep", "sleep10",
                                                                   "sleep100", "sleep1000", "sreset", "stacktrace",
                                                                   "suspend", "unsleep", "wait"};


void syscallsummary_start() {
    int i;
    for (i = 0; i < NPROC; ++i) {
        int j;
        for (j = 0; j < NUM_DEFINED_SYSCALL; ++j) {
            num_execution[i][j] = 0;
            time_execution[i][j] = 0;
        }
        is_process_executed[i] = 0;
    }

    is_tracing = 1;
}

void syscallsummary_stop() {
    is_tracing = 0;
}

void printsyscallsummary() {
    kprintf("void printsyscallsummary()\n");
    int i;
    for (i = 0; i < NPROC; ++i) {
        if (is_process_executed[i]) {
            kprintf("Process [pid:%d]\n", i);
            int j;
            for (j = 0; j < NUM_DEFINED_SYSCALL; ++j) {
                if (num_execution[i][j] > 0) {
                    int average_time = time_execution[i][j] / num_execution[i][j];
                    kprintf("\tSyscall: %s, count: %d, average execution time: %d (ms)\n", syscall_name[j], num_execution[i][j], average_time);
                }
            }
        }
    }
}