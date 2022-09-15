#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void child(int level, int index, pid_t parent){
        pid_t cpid[3]; int i=0; pid_t Lparent= getpid();
        if(level ==1 && index == 0){ // this is B
                printf("MY PID:%d, MY PARENT'S PID: %d\n", getpid(), parent);
                for(i=0;i<2;i++){ //creating D and E
                        if((cpid[i] =fork()) >0 ){
                                child(2,i,Lparent ); //here D and E calls child recursively
                        }
                }
                sleep(5);
                // B is going to kill D and E
                for(i=0;i<2;i++){
                        kill(cpid[i],SIGKILL);
                }
                sleep(5);
        }
        //write code here for C, D, E, F, and G
        else if(level ==1 && index ==1){//this is C
                printf("MY PID: %d, MY PARENT'S PID:  %d\n", getpid(), parent);
                for(i=0; i<2; i++){
                        if((cpid[i]=fork()) ==0){
							child(2,i,Lparent);//here F and G calls child() recursively
                        }
                }
                sleep(5);
                //C is going to kill F and G
                for(i=0; i<2; i++){
                        kill(cpid[i],SIGKILL);
                }
                sleep(5);
        }
        else{ //D, E ,F and G will be here
                printf("MY PID: %d, MY PARENTS PID: %d\n", getpid(),parent);
                sleep(10);
        }
        //proceed with coping code and   repeat
}
int main(){ //this process A
        pid_t cpid[2];
        int i=0; pid_t root = getpid();
        for(i =0; i<2;i++){
                if( (cpid[i] = fork())==0){ //B, C are calling child()
                        child(1,i,root);
                }
        }
        sleep(15);
		 printf("PARENT_A: Going to kill all child proceses\n");
        for(i=0; i<2; i++){
                kill(cpid[i], SIGKILL);
        }
printf("MY PID: %d\n",getpid());
return 0;
}