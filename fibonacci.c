#include<stdio.h>
int main()
{
    int num,ini=0,fin=1,i,ans;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    printf("The first %d Fibonacci series are:\n",num);
    printf("%d",ini);
    printf("%d",fin);
    for(i=3;i<=num;i++)
    {
        ans=ini+fin;
        printf("%d",ans);
        ini=fin;
        fin=ans;
    }
    return 0;
}
