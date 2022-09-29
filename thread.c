#include <stdio.h>
#include <pthread.h>
void *threadform(void *arg){
        printf("Thread: My Index: %d\n", *(int *)arg);

return NULL;
}

int main(){
        pthread_t th =0; int index=1;
        pthread_create(&th, NULL,threadform,(void *)&index );

        pthread_join(th,NULL);
return 0;
}


