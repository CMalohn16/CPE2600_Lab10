/**
 * @file receive_tennis.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/11/2026
 * @brief Receiving end for a tennis game. Run first
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
            //This process missed so the opponent gains a point
            printf("Miss\n");
            update_score(false);
        }
        else 
        {
            printf("Hit!\007\n");
        }       
    }
    else
    {
        //The opponent missed, so this process gains a point
        update_score(true);
    }
}

int main() 
{
    srand(time(NULL));

    //Call return_ball() with ball data when SIGUSR1 (BALL) is received
    struct sigaction sa;
    sa.sa_sigaction = return_ball;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        return 1;
    }

    printf("Receiving PID: %d\n", getpid());
    
    while(1) {
        sleep(1);
    }
}