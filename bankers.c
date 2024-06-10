#include<stdio.h>
int main()
{
    int n =5, m =3;
    int alloc[5][3] = {{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};
    int max [5][3] = {{7,5,3}, {3,2,2}, {9,0,2}, {2,2,2}, {4,3,3}};
    int avail[3] = {3,3,2};
    int need[n][m], f[n], ans[n], index = 0;
    for(int i =0; i<n; i++)
    {
        f[i] =0;
    }
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int c =0;
    while(c<n)
    {
        for(int i =0; i<n; i++)
        {
            if(f[i] == 0)
            {
                int flag =0;
                for(int j =0; j<m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    ans[index++] = i;
                    for(int y =0; y<m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] =1;
                    c++;
                }
            }
        }
    }
    printf("the safe sequence is: ");
    for(int i =0; i<n; i++)
    {
        printf("P%d -> ",ans[i]);
    }
}