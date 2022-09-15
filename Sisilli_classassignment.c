#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
//Class Lab Assignment
//Name: Caitlin Sisilli
//Due: 9/15/2022
bool isPrime(int N){
        int i=2;
        for(i=2;i<(int)N/2; i++){
                if(N% i==0){
                        return 0;
                }
        }
        return 1;

}
int main(){
        int fdP2C[2] ={0};
        int fdC2P[2]={0};
        pipe(fdP2C); pipe(fdC2P);
        int buffer=0;
        char *p= ""; char *c="";
        char chbuffer[1024]={""};
        if(fork() >0){
                int x=0;
                srand(time(NULL));
                x =rand()%100; //pick a random number from 0 to 100
                close(fdP2C[0]); //close read, which causes fdp2c to end
                write(fdP2C[1], &x,sizeof(x) );

                close(fdC2P[1]);
                read(fdC2P[0], chbuffer, sizeof(chbuffer));

                printf("%d is %s\n",x,chbuffer);
        }
        else{
                close(fdP2C[1]); //closes  write, which causes fdp2c to end
                read(fdP2C[0],&buffer, sizeof(buffer));
                if(isPrime(buffer)){
                        c= "Prime";
                }
                else{
                        c="Not Prime";
                }
                close(fdC2P[0]);//close C2P
                write(fdC2P[1], c , strlen(c));
        }
return 0;
}

