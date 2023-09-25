// Implementation of PIPE.
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()   
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();
    if (p > 0)
    {
        close(fd[0]);
        printf("Parent Passing value to child.\n");
        write(fd[1], "hello my child\n", 15);
        wait(NULL);
    } 
    else 
    {
        printf("Child printing received value\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
    printf("karan");
}
