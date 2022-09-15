#include <stdio.h>
#include <signal.h>
#include <unistd.h>
//Project 2: Using C to get the child/parents pid fron a tree
//Name: Caitlin Sisilli
//Due: Sep 20th,2022
void child(int level, int index, pid_t parent){
        pid_t cpid[3]; int i=0; pid_t Lparent =getpid();
        if(level=1  && index ==0){ //this is B
                printf("My Pid: %d, My Parent's Pid: %d\n", getpid(), parent);
                for(i=0; i<2; i++){//creating E and F
                        if((cpid[i] = fork()) >0){
                                child(2,i,Lparent); // Here E and F calls the child recursively
                        }
                }
                sleep(5);
                //B is going to kill E and F
                for(i=0;i<2;i++){
                        kill(cpid[i], SIGKILL);
                }
                sleep(5);
        }
        else if(level ==1 && index ==1){// this is C
                printf(" My Pid: %d, My Parent's Pid: %d\n",getpid(), parent);
                sleep(5);
        }
        else if(level ==1 && index ==2){ // this is  D
                printf("  My Pid: %d, My Parent's Pid: %d\n", getpid(), parent);
                for(i=0; i<2; i++){
                        if((cpid[i] = fork()) >0){
                                child(2,i,Lparent); //here G and H calls child() recursively
                        }
                }
                sleep(5);
                //D is going to kill G and H
                for(i=0;i<2;i++){
                        kill(cpid[i], SIGKILL);
                }
                sleep(5);
        }
        else{
                printf("My Pid: %d, My Parent's Pid: %d\n", getpid(), parent);
                sleep(10);
        }
}
int main(){ //This is Process A
        pid_t cpid[3];
        int i=0;
        pid_t root=getpid();
        for(i=0; i<3; i++){
                if((cpid[i] = fork()) == 0){ //B, C, and D are calling child()
                        child(1,i,root);
                }
        }
        sleep(15);
        printf("Parent A: Going to kill all child processes\n");
		for(i=0;i<3;i++){
            kill(cpid[i], SIGKILL);
        }
printf("My Pid: %d\n", getpid());
return 0;
}
