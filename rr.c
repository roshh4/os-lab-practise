#include<stdio.h>
int main()
{
    int n;
    printf("enter no of processes");
    scanf("%d",&n);
    int atime[n], btime[n], temp[n];
    for( int i =0; i<n; i++)
    {
        printf("enter arrival time and burst time for process %d:",i+1);
        scanf("%d %d",&atime[i],&btime[i]);
        temp[i] = btime[i];
    }
    int ts;
    printf("enter time slot");
    scanf("%d",&ts);
    int x = n, i = 0, total = 0, c =0, wt =0, tat =0;
    printf("Process no \t Burst time \t Arrival time \t Waiting time \t Turnaround time\n");
    while (x!=0)
    {
        if(temp[i] > 0 && temp[i] <= ts)
        {
            total += temp[i];
            temp[i] = 0;
            c = 1;
        }
        else if ( temp[i] > 0)
        {
            total += ts;
            temp[i] -= ts;
        }
        if(temp[i] == 0 && c == 1)
        {
            x--;
            printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", i+1, btime[i], atime[i], total - atime[i] - btime[i], total - atime[i]);
            wt += total - btime[i] - atime[i];
            tat += total - atime[i];
            c = 0;
        }
        if(i == n-1)
        {
            i =0;
        }
        else if(atime[i+1] <= total)
        {
            i++;
        }
        else{
            i = 0;
        }
    }
    printf("The average waiting time is %f\n", (float)wt/n);
    printf("The average turnaround time is %f", (float)tat/n);
}