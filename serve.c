/**
 * @file serve.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/11/2026
 * @brief Serves the tennis ball to the receiving process given its id
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tennis_scoring.h"

void return_ball(int signum, siginfo_t *info, void *context)
{
    int success = info->si_value.sival_int;
    if (success)
    {
        sleep(1);

        struct timespec tm;
        tm.tv_nsec = (rand() % ((long unsigned int)10e9));
        tm.tv_sec = 0;
        nanosleep(&tm, NULL);

        //Generate a random value 0-3.
        //If greater than 0, success (1/4 odds)
        int hit = ((rand() % 4) > 0);

        union sigval sigValue;
        sigValue.sival_int = hit;
        sigqueue(info->si_pid, BALL, sigValue);    

        if (!hit)
        {
            printf("Miss\n");
            update_score(false);
            sleep(3);
            serve(info->si_pid);
        }
        else 
        {
            printf("Hit!\007\n");
        }    
    }
    else
    {
        update_score(true);
        sleep(3);
        serve(info->si_pid);
    }
}


int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("Error: No PID provided for the receiving process\n");
        return 1;
    }

    int receiverPID = atoi(argv[1]);
    printf("Serving to PID: %d\n", receiverPID);

    // srand(time(NULL));
    // int num = rand() % 1000;

    // union sigval sigValue;
    // sigValue.sival_int = num;

    // printf("Sending value %d to process %d\n", sigValue.sival_int, pid);
    // sigqueue(pid, SIGUSR1, sigValue);

    struct sigaction sa;
    sa.sa_sigaction = return_ball;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(BALL, &sa, NULL) == -1) {
        return 1;
    }

    serve(receiverPID);

    while(1) {
        sleep(1);
    }
}
