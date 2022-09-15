#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
        int fd[2];
        pipe(fd); int  buffer =0;
        pid_t parent= getpid();
        printf("Parent: %d\n",parent);
        int a=5;
        char *ptr= ""; char chbuffer[1024];
        if (fork() >0){ //this is parent, I am writing to B
                ptr="Hello Child";
                close(fd[0]);
                write(fd[1], ptr , strlen(ptr) );
        }
        else{
                close(fd[1]);
                read(fd[0], &buffer, sizeof(buffer));
                printf("Child: a=%d\n", buffer);

        }
return 0;
}
