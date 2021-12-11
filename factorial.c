#include<stdio.h>
#include<conio.h>
void main()
{
    int num, fact= 1, i;
    printf("\n Enter a number of elements:\t");
    scanf("%d", & num);
    for (i= 1; i<= num; i++)
    {
        fact= fact* i;
    }
    printf("The factorial is:\t %d", fact);
    getch();
}
