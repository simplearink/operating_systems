#include<stdio.h> 
#include<signal.h> 
#include<unistd.h>

void handle_sigint() {
	printf("\nCaught SIGINT\n");
}

void handle_sigkill() {
	printf("\nCaught SIGKILL\n");
}

void handle_sigstop() {
	printf("\nCaught SIGSTOP\n");
}

void handle_sigusr1() {
	printf("\nCaught SIGUSR1\n");
}

  
int main() 
{ 
    signal(SIGINT, handle_sigint); 
    signal(SIGKILL, handle_sigkill); 
    signal(SIGSTOP, handle_sigstop); 
    signal(SIGUSR1, handle_sigusr1); 
    while (1) 
    {} 
    return 0; 
} 