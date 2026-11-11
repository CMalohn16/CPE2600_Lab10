/**
 * @file signal_segfault.c
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/5/2026
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Charlie Malohn
 * 
 * Brief summary of modifications:
 *   Added handler for SIGSEGV to show when a segmentation fault happens.
 */


#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message
 */
void handle_seg_fault() {
    printf("\nSegmentation fault detected\n");
}

int main (int argc, char* argv[]) {

    signal(SIGSEGV, handle_seg_fault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}