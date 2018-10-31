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
	int fd = open ("./ex1.txt", O_RDWR);
	struct stat buffer;
	fstat(fd, &buffer);
	int a = buffer.st_size;
	const char *text = "This is a nice day";
	ftruncate(fd, strlen(text));
  	size_t textsize = strlen(text) + 1;
  	lseek(fd, textsize-1, SEEK_SET);
  	write(fd, "", 1);
  	char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  	memcpy(map, text, strlen(text));
  	msync(map, textsize, MS_SYNC);
  	munmap(map, textsize);
  	close(fd);
  	return 0;
   }
