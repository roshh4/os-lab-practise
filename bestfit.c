#include<stdio.h>
#include<string.h>
int bestfit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for(int i =0; i<n; i++)
    {
        int bestInd = -1;
        for(int j = 0; j<m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(bestInd == -1)
                {
                    bestInd = j;
                }
                else if(blockSize[bestInd] > blockSize[j])
                {
                    bestInd = j;
                }
            }
        }
        if(bestInd != -1)
        {
            allocation[i] = bestInd;
            blockSize[bestInd] -= processSize[i];
        }
    }
    printf("Process No\tProcess size\tBlock no\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t%d\t\t",i+1,processSize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d\n",allocation[i]);
        }
        else{
            printf("Not Allocated");
        }
    }
}
int main()
{
    int blockSize[] = {100,500,200,300,600};
    int processSize[] = {212,417,112,426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    bestfit(blockSize, m, processSize, n);
}