//8.2 Implement FCFS (First Come First Served) Scheduling Algorithm
#include <stdio.h>
#include <unistd.h>
int main()
{
    int arrival[5] = {0 , 0 , 0 , 0 , 0}; 
    int burst[5] = {7 , 2 , 8 , 5 , 4}; 
    int wait[5] = {0 , 0 , 0 , 0 , 0};
    int tat[5] = {0 , 0 , 0 , 0 , 0}; 
    int i , sum_wait=0 , sum_tat=0; float avg_w , avg_t;
    for(i=1 ; i<5 ; i++)
    {
        wait[i] = wait[i-1]+burst[i-1]; 
    }
    for(i=0 ; i<5 ; i++)
    {
        tat[i] = wait[i] + burst[i]; sum_wait+=wait[i]; sum_tat+=tat[i];
    }
    avg_w = sum_wait/5.0;
    avg_t = sum_tat/5.0; printf("%f %f",avg_w , avg_t); 
    return 0;
}