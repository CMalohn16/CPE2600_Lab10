/**
 * @file signal_alarm.c
 * @author Charlie Malohn
 * @date 11/5/2026
 * @brief Schedules a 5 second alarm and shows when SIGALRM is received
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGALRM - prints a message and exits
 */
void handle_alarm() {
    printf("Alarm Received\n");
    printf("Exiting\n");
    exit(0);
}

/**
 * @brief Handles keyboard interrupt
 */
void handle_keyboard() {
    printf("\nKeyboard interrupt\n");
    printf("Exiting\n");
    exit(1);
}

int main() {

    // Register for the signals
    signal(SIGALRM, handle_alarm);
    signal(SIGINT, handle_keyboard);

    // Start alarm timer
    alarm(5);

    // Wait until alarm is received
    while(1) {
        sleep(1);
    }

    return 0;
}