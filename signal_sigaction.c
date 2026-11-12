/**
 * @file signal_sigaction.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/10/2026
 * @brief Waits for USR1 signal and prints a message when received
 *         To send this signal, use the command $ kill -SIGUSR1 <PID>
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Sender Process ID: %d\n", info->si_pid);
    exit(0);
}

 int main (int argc, char* argv[]) 
 {
    struct sigaction action;
    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        return 1;
    }
    
    // Wait until a signal is received
    // To send a SIGUSR1 signal to the program, use $ kill -SIGUSR1 <PID>
    while(1) {
        sleep(1);
    }

    return 0;
 }