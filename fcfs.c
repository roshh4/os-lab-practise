#include<stdio.h>
int main()
{
    int n;
    printf("enter no of process");
    scanf("%d",&n);
    char name[n][20];
    int btime[n];
    for(int i =0; i <n; i++)
    {
        printf("enter process name and burst time");
        scanf("%s %d",name[i],&btime[i]);
    }
    int ct[n], ctt=0, bt=0;
    for(int i = 0; i<n; i++)
    {
        ctt += btime[i];
        ct[i] = ctt;
    }
    printf("process name \t burst time \t waiting time \t turnaround time\n");
    for(int i =0 ; i<n; i++)
    {
        printf("%s \t\t %d \t\t %d \t\t %d\n",name[i],btime[i],bt,ct[i]);
        bt += btime[i];
    }
    printf("The average waiting time is %f\n", (float) (bt - btime[n-1])/n);
    printf("The average turnaround time is %f", (float) ctt/n);
}