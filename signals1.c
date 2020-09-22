/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_invoked = 0;
void handler(int signum) { //signal handler
  handler_invoked = 1;
  printf("Hello World!\n");
}

int main(int argc, char * argv[]) {
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  sleep(1); //delay 1 second
  while(handler_invoked == 1) { //busy wait for signal to be delivered
    printf("Turing was right!\n");
    handler_invoked = 0;
  }
  return 0; //never reached
}