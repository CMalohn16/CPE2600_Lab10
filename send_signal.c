/**
 * @file send_signal.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/11/2026
 * @brief Sends SIGUSR1 with a randomly generated integer
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Error: No PID provided for the receiving process\n");
        return 1;
    }

    int pid = atoi(argv[1]);

    srand(time(NULL));
    int num = rand() % 1000;

    union sigval sigValue;
    sigValue.sival_int = num;

    printf("Sending value %d to process %d\n", sigValue.sival_int, pid);
    sigqueue(pid, SIGUSR1, sigValue);

    return 0;
}
