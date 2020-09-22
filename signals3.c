/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int seconds = 0; // i.e. alarms occured
void handler(int signum) { //signal handler
  seconds++;
}

void timer(int signum) {
  printf("\nTime in execution: %ds\n", seconds);
  exit(1);
}

int main(int argc, char * argv[]) {
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,timer); //register handler to handle SIGINT

  while(1) { //busy wait for signal to be delivered
    alarm(1);
    sleep(1);
  }
  return 0; //never reached
}