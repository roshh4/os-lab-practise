#include<stdio.h>
int main()
{
    int n;
    printf("enter no of processes");
    scanf("%d",&n);
    int p[n], name[n], btime[n];
    for(int i =0; i<n; i++)
    {
        printf("enter process name, burst time and priority");
        scanf("%d %d %d",&name[i],&btime[i],&p[i]);
    }
    for(int i =0; i<n; i++)
    {
        int pos = i;
        for(int j = i+1; j<n; j++)
        {
            if(p[j] > p[pos])
            {
                pos = j;
            }
        }
        int temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
        temp = btime[pos];
        btime[pos] = btime[i];
        btime[i] = temp;
        temp = name[i];
        name[i] = name[pos];
        name[pos] = temp;
    }
    int ct[n], ctt = 0, bt = 0;
    for(int i = 0; i<n; i++)
    {
        ctt += btime[i];
        ct[i] = ctt;
    }
    printf("Process name \t Priority \t Burst time \t Waiting time \t Turnaround time\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n",name[i], p[i], btime[i], bt, ct[i]);
        bt += btime[i];
    }
    printf("the average waiting time is %f\n", (float)(bt - btime[n-1])/n);
    printf("the average turnaround time is %f", (float)(ctt)/n);
}