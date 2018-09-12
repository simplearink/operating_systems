#include <stdio.h>
#include <stdlib.h>


void print_cursor() {
	printf(">");
}


void read_command(char *command) {
	scanf("%s", command);
}
int main(void) {
 	while(1) {
 		char command[100];
 		print_cursor();
 		read_command(command);
 		system(command);
 	}
}