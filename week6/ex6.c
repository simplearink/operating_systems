#include<stdio.h> 
#include<signal.h> 
#include<unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

  
int main() {

  pid_t child1, child2;
  int channel[2];
  pipe(channel);
  child1 = fork();

  if (child1 > 0) {
    child2 = fork();
    if (child2 > 0) {
      int status_code;
      printf("P: I'm a parent\n");
      write(channel[1], &child2, 10);
      close(channel[0]);
      close(channel[1]);
      waitpid(child2, &status_code, 0);
      printf("P: Child #2 is killed!\n");
      printf("P: I'm terminating!\n");

    } else if (child2 == 0) {
      printf("2: Child #2 is created\n");
      while(1);
    }
  } else if (child1 == 0) {
    printf("1: Child #1 is created\n");
    int status = 0;
    read(channel[0], &status, 10);
    close(channel[0]);
    printf("1: I know child's #2 PID! Child #2 PID is %d\n", status);
    sleep(3);
    printf("1: Sending SIGSTOP to Child #2!\n");
    kill(status, SIGSTOP);
    printf("1: SIGSTOP is sent to Child #2!\n");

    printf("1: Sending SIGKILL to Child #2!\n");
    kill(status, SIGKILL);
    printf("1: SIGKILL is sent to Child #2!\n");
  }  
} 