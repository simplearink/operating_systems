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

int main(int argc, char **argv){

    int source, destination;
    char *src, *dest;
    size_t fs;

    source = open("ex1.txt", O_RDONLY);
    fs = lseek(source, 0, SEEK_END);

    src = mmap(NULL, fs, PROT_READ, MAP_PRIVATE, source, 0);

    destination = open("ex1.memcopy.txt", O_RDWR);
    ftruncate(destination, fs);

    dest = mmap(NULL, fs, PROT_READ | PROT_WRITE, MAP_SHARED, destination, 0);

    memcpy(dest, src, fs);

    munmap(src, fs);
    munmap(dest, fs);

    close(source);
    close(destination);

   return 0;
}