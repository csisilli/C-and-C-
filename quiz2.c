#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFF_SIZE 50
int next_in = 0, next_out = 0;
// mutex
pthread_mutex_t mutex;
int buffer[BUFF_SIZE];
sem_t empty, full;
// initialize BUFF_SIZE and full to 0
void *access_buffer(void *arg)
{
    int item, x;
    int *id = (int*)arg;
    x = *id;
    if(x%2 == 0)
    {
        for(int i = 0; i < 200; i++)
        {
            sem_wait(&empty);
            pthread_mutex_lock(&mutex);
            item = rand();
            buffer[next_in] = item;
            printf("Producer has produced an item = %d at location = %d in the buffer\n", item, next_in);
            next_in = (next_in+1)%BUFF_SIZE;
            pthread_mutex_unlock(&mutex);
            sem_post(&full);
            sleep(1);
        }
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            sem_wait(&full);
            pthread_mutex_lock(&mutex);
            item = buffer[next_out];
            printf("Consumer has consumed an item = %d from location = %d in the buffer\n", item, next_out);
            next_out = (next_out+1)%BUFF_SIZE;
            pthread_mutex_unlock(&mutex);
            sem_post(&empty);
            sleep(1);
        }
    }

}

int main ()
{
// join the threads and exit
int val = 2;
int val1 = 3;
sem_init(&full, 1, 0);
sem_init(&empty, 1, BUFF_SIZE);
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("\n Mutex intialization in failed, try again.\n");
        return 1;
    }
    pthread_t thread_id1, thread_id2;
    printf("Before Thread\n");
    pthread_create(&thread_id1, NULL, access_buffer, (void*)&(val));
    pthread_create(&thread_id2, NULL, access_buffer, (void*)&(val1));
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("After Thread\n");
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    exit(0);

}