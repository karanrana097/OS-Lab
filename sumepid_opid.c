// Implement a program that computers sum of odd numbers in parent process and sum of even numbers in child process using fork system call.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int arr[10];
    int a,n,sume=0,sumo=0;
    printf("Enter Size of an Array :"); scanf("%d",&n);
    printf("Enter Array:\n");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&arr[i]);
    }
    a=fork();
    if(a>0){
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0)
            {
                sumo=sumo+arr[i];
            }
        }
        printf("Sum of odd(Parent)=%d\n",sumo); 
        exit(0);
    }
    else if(a==0)
    {
        for(int i=0;i<n;i++) 
        {
            if(arr[i]%2==0)
            {
                sume=sume+arr[i];
            }
        }
        printf("sum of even(child)= %d\n",sume); exit(0);
    }else
    {
        printf("unsuccessful ceation of process\n");
    }
}