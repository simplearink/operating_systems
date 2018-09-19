#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_sth(void *vargp){ 
	int *myid = (int *)vargp;
    printf("Thread %d is created\n", *myid);
    fflush(stdout);
    pthread_exit(0);
    return NULL;
}

int main(int argv, char**argc) {
	int n = atoi(argc[1]);
    pthread_t thread_id[n];

    for (int i = 0; i < n; i ++) {
    	printf("Start thread #%d \n", i);
    	fflush(stdout);
        pthread_create(&thread_id[i], NULL, print_sth, (void*) &thread_id[i]);
        pthread_join(thread_id[i], NULL); 
        printf("Finish thread #%d \n", i);
        fflush(stdout);
    }
	return 0;
}