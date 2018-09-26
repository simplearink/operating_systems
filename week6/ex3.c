#include<stdio.h> 
#include<signal.h> 
#include<unistd.h>

void handle_sigint() {
	printf("\nCaught SIGINT\n");
}

  
int main() 
{ 
    signal(SIGINT, handle_sigint); 

    while (1) 
    { 
        printf("Just typing...\n"); 
        sleep(1); 
    } 
    return 0; 
} 