  GNU nano 4.8                                          forktext1.c                                                     #include <stdio.h>
#include <unistd.h>
int main(){
        printf("MY PID: %d\n", getpid());
        int var =5;
        int id=0;
        if ((id =fork() ) !=0){
                int *ptr =&var;
                var=var+1;
                printf("Im the parent process, MY PID:%d, id-value: %d\n", getpid(), id);
                printf("PARENT: var_value:%d,  var_address %p\n",var ,ptr);

        }
        else {
                int *ptr =&var;
                printf("Im the child process, MY PID:%d, id-value: %d\n", getpid(),id);
                printf("CHILD: var_value: %d, var_address %p\n",var ,ptr);
        }
        sleep(3);
return 0;
}