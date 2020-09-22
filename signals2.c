/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) { //signal handler
  printf("Hello World!\n");
}

int main(int argc, char * argv[]) {
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1) { //busy wait for signal to be delivered
    alarm(1);
    sleep(1); // delay 1 second
    printf("Turing was right!\n");
  }
  return 0; //never reached
}