/**
 * @file tennis_scoring.h
 * @author Charlie Malohn
 * @class CPE 2600 - 121
 * @date 11/12/2026
 * @brief Declarations for tennis functions
 */

#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define BALL SIGUSR1

bool update_score(bool myPoint);
void serve(int id);