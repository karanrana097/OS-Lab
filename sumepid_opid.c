//WAP to in which parent calculates sum of even process and child process calculates sum of odd processes.
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int a[10];
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int m=fork();
    int sum = 0;
    if(m>0)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==0)
                sum+=a[i];
        }
        printf("\nParent process executed and sum is %d :",sum);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]%2!=0)
                sum+=a[i];
        }
        printf("\nChild process executed and sum is %d :",sum);
    }
}