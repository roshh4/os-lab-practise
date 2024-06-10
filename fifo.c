#include<stdio.h>
int main()
{
    int pagefaults =0, frames =3;
    int incoming[] = {4,1,2,4,5};
    int pages = sizeof(incoming)/sizeof(incoming[0]);
    int temp[frames];
    for(int i=0;i<frames;i++)
    {
        temp[i] = -1;
    }
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3");
    for(int i = 0; i<pages;i++)
    {
        int s =0;
        for(int j=0;j<frames;j++)
        {
            if(incoming[i] == temp[j])
            {
                s++;
                pagefaults--;
            }
        }
        pagefaults++;
        if(s==0 && pagefaults<=frames)
        {
            temp[i] = incoming[i];
        }
        else if(s==0)
        {
            temp[(pagefaults-1)%frames] = incoming[i];
        }
        printf("\n");
        printf("%d\t\t",incoming[i]);
        for(int j =0; j<frames;j++)
        {
            if (temp[j]!=-1)
            {
                printf("%d\t\t",temp[j]);
            }
            else{
                printf("-\t\t");
            }
        }
    }
    printf("\nTotal no of page faults is %d", pagefaults);

}