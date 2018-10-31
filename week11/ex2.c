#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
	setvbuf(stdout, 0, _IOLBF, 6);
	printf("h");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);
	printf("\n");

  	return 0;
   }