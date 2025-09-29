#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t seconds = 0;

void alarm_handler(int signum) {
    seconds++;
    alarm(1);   // schedule next alarm in 1 second
}

void int_handler(int signum) {
    printf("\nProgram executed for %d seconds.\n", seconds);
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, int_handler);

    alarm(1);   // start timer

    while (1) {
        pause();  // wait for signals
    }
}
