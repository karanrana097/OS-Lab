// 2. Implementation of multiple fork( ) ans use of PID and  PPID.
#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("This is demo of fork system call\n"); 
    fork();
    printf("ID:%d\n",getpid());
    printf("Parent Id: %d\n",getppid());
    fork();
    printf("Hello\n"); 
    printf("ID:%d\n",getpid());
    printf("Parent ID:%d\n",getppid());
    return 0; 
}