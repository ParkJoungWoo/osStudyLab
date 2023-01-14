#include<stdio.h>
#include<unistd.h>
#include<wait.h>

int main(){
    pid_t pid;
    // 자식을 fork
    pid = fork();
    if(pid<0){ // 에러가 발생한 경우
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if(pid == 0){ // 자식 프로세스인 경우
        execlp("/bin/ls", "ls", NULL);
    } else { // 부모 프로세스인 경우
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}