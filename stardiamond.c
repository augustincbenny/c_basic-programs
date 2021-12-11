#include<stdio.h>
int main()
{
    int row, i, j, s;
    printf("\n Enter the number of rows: ");
    scanf("%d",&row);

    // 1st HALF OF DIAMOND

    // OUTER LOOP FOR NEW LINES                              

    for (i=1; i<=row/2; i++)
    {
        printf("\n");

    // 2nd LOOP FOR PRINTING THE SPACES

        for(s=1; s<=(row-i); s++)
        {
            printf(" ");
        }

    // 3rd LOOP FOR PRINTING STAR     

        for(j=1; j<=i; j++)
        {
            printf("* ");
        }
    }

    // 2nd HALF OF DIAMOND

    // OUTER LOOP FOR NEW LINES

    for (i= row- (row/2) ; i>=1 ; i--)
    {
        printf("\n");

    // 2nd LOOP FOR PRINTING THE SPACES

        for(s=1; s<=(row-i); s++)
        {
            printf(" ");
        }

    // 3rd LOOP FOR PRINTING STAR     

        for(j=i; j>=1; j--)
        {
            printf("* ");
        }
    }
    return 0;
}
