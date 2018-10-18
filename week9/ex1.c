#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Page
    {
        int pageNum;
        int history;
    };

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    int counter = 0;
    int faultCounter = 0;
    char buf[10];
    struct Page pageTable[n];

    for (int i = 0; i < n; i++) {
        pageTable[i].pageNum = 0;
        pageTable[i].history = 0;
    }

    FILE *fp;
    fp = fopen("input.txt", "r"); 
 
    if (fp == NULL)
    {
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }

    while(fscanf(fp, "%s", buf) == 1) {
        int ch = atoi(buf);
        counter++;
        int isInPageTable = 0;
        for (int i = 0; i < n; i++) {
            if (ch == pageTable[i].pageNum) {
                isInPageTable = 1;
                pageTable[i].history = div(pageTable[i].history, 2).quot + 128;  /* 128 = 2^7, if we make right shift, we divide by 2,
                                                                       if we add 1 at the beginning of 8-bit binary, we add 128*/
            }
        }
        if (isInPageTable == 0) {
                faultCounter++;
                int min = pageTable[0].history;
                int minIter = 0;
                for (int j = 1; j < n; j++) {
                    if (pageTable[j].history < min) {
                        min = pageTable[j].history;
                        minIter = j;
                    }
                    pageTable[j].history = div(pageTable[j].history, 2).quot;
                }
                pageTable[minIter].pageNum = ch;
                pageTable[minIter].history = 128;
            }
        }

    fclose(fp);
    int hits = counter - faultCounter;
    printf("Hit/miss ratio is: %d/%d \n", hits, faultCounter);
    
	return 0;
}
