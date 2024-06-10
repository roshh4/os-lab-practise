#include<stdio.h>
int LRU(int time[], int n)
{
    int pos,min = time[0];
    for(int i =1; i<n;i++)
    {
        if(time[i]<min)
        {
            min = time[i];
            pos =i;
        }
    }
    return pos;
}
int main()
{
    int nop, nof;
    printf("enter no of pages and frames");
    scanf("%d %d",&nop,&nof);
    int pages[nop], frames[nof],time[nof],faults =0, c=0,pos;
    for(int i =0; i<nop;i++)
    {
        printf("enter size of page %d: ",i+1);
        scanf("%d",&pages[i]);
    }
    for(int i = 0; i<nof;i++)
    {
        frames[i] = -1;
    }
    for(int i=0; i<nop; i++)
    {
        int flag1 =0, flag2 =0;
        for(int j =0; j<nof; j++)
        {
            if(pages[i]==frames[j])
            {
                c++;
                time[j] = c;
                flag1 = flag2 =1;
                break;
            }
        }
        if(flag1==0)
        {
            for(int j =0; j<nof;j++)
            {
                if(frames[j]==-1)
                {
                    c++;
                    time[j] = c;
                    frames[j] = pages[i];
                    faults++;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2 ==0)
        {
            pos = LRU(time, nof);
            c++;
            time[pos] = c;
            faults++;
            frames[pos] = pages[i];
        }
        printf("\n");
        for(int j=0;j<nof;j++)
        {
            printf("%d\t",frames[j]);
        }
    }
}