#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define size 5
#define iter 10000
char *mystring ="Hello";
int count =0;
void *threadfun(void *arg){
        int idx=*(int *)arg;
        pthread_exit( *(void *)mystring[idx]  );

}

int main(){
        pthread_t th[size]; int idx[size]={0,1};
        int i=0; pthread_attr_t my attr; int *myretval;
        pthread_attr_init(&myattr);
        for(i=0;i<size;i++){
                pthread_create(&th[i], &myattr, threadfun, (void *)&idx[i];
        }
        for(i=0;i<size;i++){
                pthread_join(th[i], (void **)&myretval);
                printf("Returned value from THRD_ID: %d is %d\n",i, *myretval);
                free(myretval);
        }
        printf("%p, %d\n", myretval, *myretval);
        printf("");
        pthread_attr_destroy(&myattr);
return 0;
}