// 6. Demonstrate Orphan process
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
    pid_t id;
    id=fork();
    if(id>0)
    {
        printf("parent process\n"); 
        printf("%d\t%d\n",getpid(),getppid()); 
        exit(0);
    }
    else if(id==0)
    {
        printf("Child process\n");
        sleep(5); 
        printf("%d\t%d\n",getpid(),getppid());
    }
}

