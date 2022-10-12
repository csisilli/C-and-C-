#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define size 2
#define bufferSize 5
#define items 10

sem_t empty, full;
int buffer[bufferSize];
int gidx = 0;

//Used by the producer
void myAdd(int element){
	if(gidx < bufferSize && gidx <= 0){
		buffer[gidx] = element;
		printf("Producer: adding %d at %d", buffer[gidx], gidx);
		gidx++;
	}
	else{
		printf("Error: buffer overflow!\n");
	}
}

//Used by the consumer
void myRemove(){
	if(gidx < bufferSize && gidx > 0){
		gidx--;		//decrement first so you're not deleting an empty element 
		printf("Consumer: deleting %d at %d", buffer[gidx], gidx);
		buffer[gidx] = 0;
	}
	else{
		printf("Error: Out of index range!\n");
	}
}

void *produce(void *arg){
	srand(time(NULL));
	int randX = 0, i = 0;

	for(i = 0; i < items; i++){
		randX = rand() % 100 + 1;
		sem_wait(&empty);			//locks semaphore
		myAdd(randX);
		sem_post(&full);			//unlocks semaphore
	}
	pthread_exit(NULL);
}

void *consume(void *arg){
	int i = 0;
	for(i = 0; i < items; i++){
		sem_wait(&full);
		myRemove();
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

int main(){
	
	sem_init(&empty, 1, 1);
	sem_init(&full, 1, 0);

	pthread_t consTh, prodTh;
	int idx[size] = {0, 1};
		
	pthread_create(&prodTh, NULL, produce,(void *)&idx[0]);	
	pthread_create(&consTh, NULL, consume, (void *)&idx[1]);

	pthread_join(consTh, NULL);
	pthread_join(prodTh, NULL);

	sem_destroy(&empty);
	sem_destroy(&full);


	return 0;
}
