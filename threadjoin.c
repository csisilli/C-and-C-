#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int A[10] ={1,2,3,4,5,6,7,8,9,10};
#define size 4

void *threadfun(void *arg){
//      int sum=0;
        int i=0;
        int id= *(int *) arg;
        int  *ptr= (int *)calloc(1,sizeof(int) );
        if(id ==0){
                for(i=0;i<4;i++){
                        *(ptr+0)=*(ptr+0)+A[i];
                }
        }
        if(id ==1){
                for(i=4; i<8;i++){
                        ptr[0]=ptr[0]+A[i];
                }
        }
        printf("THID: %d, sum: %d addr(sum) %p\n", id,*ptr,ptr);
        pthread_exit((void *)ptr);
}
int main(){
        pthread_t th[size]; int idx[size] ={0,1};
        int i=0; pthread_attr_t myattr; void *retval;
        pthread_attr_init(&myattr);
        for(i=0; i<size; i++){
                pthread_create(&th[i],&myattr, threadfun, (void *)&idx[i] );
        }

        for (i=0; i<size;i++){
                pthread_join(th[i],&retval);
                printf("Returned value from THRD_ID: %d\n", i, *(int *)retval  );
        }
        printf("%p\n", retval);
//free (myretval);
        pthread_attr_destroy(&myattr);

return 0;
}
