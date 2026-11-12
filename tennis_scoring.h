
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define BALL SIGUSR1

bool update_score(bool myPoint);
void serve(int id);