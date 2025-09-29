#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_signal = 0;

void handler(int signum) {
    printf("Hello World!\n");
    got_signal = 1;  // let main know signal arrived
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, handler);   // register handler
    alarm(5);                   // schedule alarm in 5 seconds

    while (!got_signal);        // busy wait until handler runs

    printf("Turing was right!\n");
    return 0;
}
