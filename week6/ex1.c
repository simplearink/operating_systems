#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 



int main() {
	int spy[2];
	pipe(spy);
	char init_str[7] = "Hello!";
	write(spy[1], init_str, 7);

	char str[7]; 
	read(spy[0], str, 7);
	printf("%s\n",str);
	close(spy[0]);
	close(spy[1]);
}