#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
	DIR *dir = opendir("./tmp");
	struct dirent *a;
	while ((a=readdir(dir))!=NULL) {
		struct stat buffer;
		stat(a->d_name, &buffer);

		if (buffer.st_nlink >= -1) {
			printf("%s %ld\n ", a->d_name, buffer.st_nlink-2);
		}
	}
}