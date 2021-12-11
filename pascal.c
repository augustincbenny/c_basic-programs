// WITH SPACES
// TOTAL ROW NO. - CORRESPONDINGROW N0.= SPACES
// Eg.   3 rows - 1st row = 2 spaces        *
//       3 rows - 2nd row = 1 spaces       *  *
//       3 rows - 3rd row = 0 spaces      *  *  *


#include<stdio.h>
int main()
{
    int row, i, j, s, temp;
    printf("Enter the rows required: ");
    scanf("%d",&row);

    // OUTER LOOP FOR NEW LINES                              

    for (i=0; i<row; i++)
    {
        printf("\n");

    // 2nd LOOP FOR PRINTING THE SPACES

        for(s=0; s<(row-i); s++)
        {
            printf(" ");
        }
    //WE ARE ASSIGNING A TEMPORARY VALUE

        temp=1;

    // 3rd LOOP FOR PRINTING VALUES  (there is slight change in range of j given)

        for(j=0; j<=i; j++)
        {
            printf("%d ",temp);
            temp= temp*(i-j)/(j+1);            
        }
    }
    return 0;
}
