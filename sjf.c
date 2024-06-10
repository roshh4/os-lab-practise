#include<stdio.h>
int main()
{
    int n;
    printf("enter no of processes");
    scanf("%d",&n);
    int name[n], btime[n];
    for(int i =0; i<n; i++)
    {
        printf("enter process no and burst time");
        scanf("%d %d",&name[i],&btime[i]);
    }
    for(int i =0; i<n; i++)
    {
        int pos = i;
        for(int j = i+1; j<n; j++)
        {
            if( btime[j] < btime[pos])
            {
                pos = j;
            }
        }
        int temp = btime[i];
        btime[i] = btime[pos];
        btime[pos] = temp;
        temp = name[i];
        name[i] =  name[pos];
        name[pos] = temp;
    }
    int ct[n], ctt =0, bt =0;
    for(int i =0; i<n;i++)
    {
        ctt += btime[i];
        ct[i] = ctt;
    }
    printf("process no \t burst time \t waiting time \t turnaround time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d\n",name[i],btime[i],bt, ct[i]);
        bt += btime[i];
    }
    printf("the average waiting time is %f", (float)(bt - btime[n-1])/n);
    printf("the average turnaround time is %f", (float)ctt/n);

}