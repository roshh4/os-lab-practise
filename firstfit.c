// #include<stdio.h>
// int main()
// {
//     int nf,nb;
//     printf("enter size of files and blocks");
//     scanf("%d %d",&nf,&nb);
//     int frag[nf], f[nf], b[nb],temp;
//     static int bf[20], ff[20];
//     for(int i=0;i<nf;i++)
//     {
//         printf("enter size of file %d: ",i+1);
//         scanf("%d",&f[i]);
//     }
//     for(int i=0;i<nb;i++)
//     {
//         printf("Enter size of block%d: ",i+1);
//         scanf("%d",&b[i]);
//     }
//     for(int i =0; i<nf;i++)
//     {
//         for(int j =0; j<nb; j++)
//         {
//             if(bf[j] != 1)
//             {
//                 temp = b[j] - f[i];
//                 if(temp >= 0)
//                 {
//                     ff[i] = j;
//                     break;
//                 }
//             }
//         }
//         frag[i] = temp;
//         bf[ff[i]] = 1;
//     }
//     printf("Process No\tProcess Size\tBlock no\t Block Size\tfragment\n");
//     for(int i=0; i<nf;i++)
//     {
//         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,f[i],ff[i],b[ff[i]],frag[i]);
//     }
// }
#include<stdio.h>
int main()
{
    int nf, nb;
    printf("enter no of files and blocks");
    scanf("%d %d",&nf,&nb);
    int frag[nf], f[nf],b[nb],temp;
    static int bf[20], ff[20];
    for(int i=0;i<nf;i++)
    {
        printf("enter size of file %d ",i+1);
        scanf("%d",&f[i]);
    }
    for(int i=0;i<nb;i++)
    {
        printf("enter size of block %d ",i+1);
        scanf("%d",&b[i]);
    }
    for(int i=0;i<nf;i++)
    {
        for(int j=0;j<nb;j++)
        {
            if(bf[j]!=1)
            {
                temp = b[j] - f[i];
                if(temp >=0)
                {
                    ff[i] =j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size\tFragment\n");
	for(int i =0; i<nf; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,f[i],ff[i]+1,b[ff[i]],frag[i]);
}