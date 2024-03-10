/*
FCFS Scheduling Program
*/

#include<stdio.h>
int main()
{
    int pid[5];
    int bt[15];
    int n;
    printf("enter the number of processes:");
    scanf("%d",&n);
    printf("enter process id of all processes:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("enter burst time of all the processes:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &bt[i]);
    }
    int i, wt[n];
    wt[0] = 0;

    //*for calculating waiting time for each process*//
    for(i=1; i<n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
        
    }
    printf("processID Burst time waiting time turnaround time\n");
    float twt = 0.0;
    float tat = 0.0;
    for(i=0;i<n;i++)
    {
        printf("&d\t\t", pid[i]);
        printf("&d\t\t", bt[i]);
        printf("&d\t\t", wt[i]);
        /*calculating and printing turn around time of each process*/
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
        //for calculating total waiting time
        twt += wt[i];
        //for calculating total turnaroung time
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
    //for calculating average waiting time
    awt = twt/n;
    //for calculating average turnaround time
    att = tat/n;
    printf("Average waiting time = %f\n", awt);
    printf("Average turnaround time = %f\n", att);
}