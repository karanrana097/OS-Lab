// 3. Get process ID’s of Child and Parent process
#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid;
    pid=fork();
    if(pid==0)
    {
        printf("Child process created with id :%d\n",getpid());
        printf("Parent process created with id :%d\n",getppid()); 
    }
    if(pid>0) 
    {
        printf("Child process returns some value to its parent"); 
    }
    return 0; 
}