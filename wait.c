// 5. Demonstrate the working of wait() system call
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t id;
    int i;
    id=fork();
    if(id==0)
    {
        for(i=0;i<10;i++)
        {
            printf("Hello I am Child\n");
        }
    }
    else if(id>0)
    {
        printf("HELLO\n");
        sleep(5);
        wait(NULL);
        for(i=0;i<10;i++)
        {
            printf("Hello I am parent\n");
        }
    }
}