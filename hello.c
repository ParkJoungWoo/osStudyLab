#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	pid_t pid;

	pid = fork();

	printf("Hello WSL!\n");

	return 0;
}
