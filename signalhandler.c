#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>

static void sig(int signo){
    if (signo == SIGINT){
        printf("Writing signal to file...\n");
        int file = open("sig.txt",O_CREAT | O_APPEND | O_RDWR, 0777);
        write(file,"Program exit: SIGINT\n",21);
        close(file);
        exit(0);
    }
    if (signo == SIGUSR1){
        printf("Parent PID: %d\n",getppid());
    }

}

int main(){
    signal(SIGINT,sig);
    signal(SIGUSR1,sig);

    while(1){
        printf("This PID: %d\n",getpid());
        sleep(1);
    }

    return 0;
}
