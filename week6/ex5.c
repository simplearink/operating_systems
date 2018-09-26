#include<stdio.h> 
#include<signal.h> 
#include<unistd.h>
  
int main() 
{ 
    pid_t a;
    a = fork();

    if (a > 0) {
        sleep(10);
        kill(a, SIGTERM);
    } else if (a == 0) {
       while (1) 
       {
        printf("I'm a child and I'm alive!\n");
        sleep(1);
       } 
    }
} 