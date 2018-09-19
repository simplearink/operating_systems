#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 8
#define TRUE 1
#define FALSE 0

int counter = 0;
int producer_is_active = TRUE;
int consumer_is_active = FALSE;

int produce_item() {}

void insert_item() {}

int remove_item() {}

void make_sleep(int *thread_status) {
    *thread_status = FALSE;
    while (*thread_status == FALSE) {
        if (*thread_status == &producer_is_active) {
            printf("Counter: %d\tProducer is sleeping\n", counter);
        }
        if (*thread_status == &consumer_is_active) {
            printf("Counter: %d\tConsumer is sleeping\n", counter);
        }
    }
}

void wake_up(int *thread_status) {
    if (*thread_status == FALSE) *thread_status = TRUE;
    if (*thread_status == &producer_is_active) {
            printf("Counter: %d\tProducer woke up\n", counter);
        }
        if (*thread_status == &consumer_is_active) {
            printf("Counter: %d\tConsumer woke up\n", counter);
        }
}

void *consumer() {
    int item;

    while (TRUE) {
        if (counter == 0) make_sleep(&consumer_is_active);
        item = remove_item();
        counter--;

        printf("Item was removed\nCounter: %d\n", counter);

        if (counter == N - 1) wake_up(&producer_is_active);
    }

}

void *producer() {
    int item;

    while (TRUE) {
        if (counter == N) make_sleep(&producer_is_active);
        item = produce_item();
        counter++;

        printf("Item was inserted\nCounter: %d\n", counter);

        if (counter == 1) wake_up(&consumer_is_active);
    }

}

int main() {
    pthread_t pthread_producer, pthread_consumer;

    pthread_create(&pthread_producer, NULL, producer, NULL);
    pthread_create(&pthread_consumer, NULL, consumer, NULL);

    pthread_exit(NULL);
	
	return 0;
}