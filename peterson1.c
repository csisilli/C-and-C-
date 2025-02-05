#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define FALSE 0
#define TRUE 1
#define N 2
#define size  10000

int turn;
int interested[N];
int count =0; //shared counter

pthread_mutex_t mylock; //this is binary lock

void enter_region(int process)
{
        int other;

        other =1-process;
        interested[process]=TRUE;
        turn=process;
        while(turn == process && interested[other]==TRUE ) {printf("THID: %d\n", pr>//null statement
}

void leave_region(int process)
{
        interested[process] =FALSE;
}

void sharedcount(){
        int i=0;
        for(i=0; i<size; i++){
                count++;
        }
}
void *threadFun(void *arg){
        int id = *(int *)arg;
//      enter_region(id);
        pthread_mutex_lock(&mylock); //lock the shared resouce
        sharedcount(); //this is critical section
//      leave_region(id);
        pthread_mutex_unlock(&mylock);
//      printf("THID: %d\n"  );
}

int main(){
        pthread_t th0, th1; int id[N]= {0,1};
        pthread_mutex_init(&mylock,NULL);
        pthread_create(&th0,NULL, threadFun, &id[0]);
        pthread_create(&th1,NULL, threadFun, &id[1]);

        pthread_join(th0,NULL);
        pthread_join(th1,NULL);

        pthread_mutex_destroy(&mylock);
        printf("COUNT: %d\n",count);

return 0;

}
