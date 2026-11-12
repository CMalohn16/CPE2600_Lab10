/**
 * @file recv_signal.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/11/2026
 * @brief Waits for SIGUSR1 and prints the data value sent with it.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int signum, siginfo_t *info, void *context)
{
    int num = info->si_value.sival_int;
    printf("Received value: %d\n", num);
    exit(0);
}

int main() 
{
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        return 1;
    }

    printf("Receiving PID: %d\n", getpid());
    
    while(1) {
        sleep(1);
    }
}