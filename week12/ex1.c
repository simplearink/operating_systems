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
	system("cat /dev/random | tr -dc 'a-zA-Z0-9' | fold -w 20 | head -n 1");
  	return 0;
   }