// // WITHOUT SPACE 

// #include<stdio.h>
// int main()
// {
//     int row, i, j;
//     printf("\nEnter the rows required: ");
//     scanf("%d", & row);

//     // OUTER LOOP FOR NEW LINES                              

//     for (i= 1; i<= row; i++)
//     {
//         printf("\n");

//     // INNER LOOP FOR PRINTING STAR     (INORDER TO GET NUMBERS, REPLACE * with %d of j)

//         for(j= 1; j<= i; j++)
//         {
//             printf("* ");
//         }
//     }
//     return 0;
// }


// ----------------------------------------------------------------------------------------------------------------------------------------


// // WITH SPACES

// // TOTAL ROW NO. - CORRESPONDINGROW N0.= SPACES
// // Eg.   3 rows - 1st row = 2 spaces      *
// //      3 rows - 2nd row = 1 spaces     *  *
// //      3 rows - 3rd row = 0 spaces    *  *  *  


// #include<stdio.h>
// int main()
// {
//     int row, i, j, s;
//     printf("\n Enter the rows required: ");
//     scanf("%d",&row);

//     // OUTER LOOP FOR NEW LINES                              

//     for (i=1; i<=row; i++)
//     {
//         printf("\n");

//         // 2nd LOOP FOR PRINTING THE SPACES

//         for(s=1; s<=(row-i); s++)
//         {
//             printf(" ");
//         }

//         // 3rd LOOP FOR PRINTING STAR     (INORDER TO GET NUMBERS, REPLACE * with %d of j)

//         for(j=1; j<=i; j++)
//         {
//             printf("* ");
//         }
//     }
//     return 0;
// }

// /* OR, we can take limits as

//     // OUTER LOOP FOR NEW LINES

//     for (i= 0; i< row; i++)
//     {
//         printf("\n");

//         // 2nd LOOP FOR PRINTING THE SPACES

//         for(s= 0; s< (row-i); s++)
//         {
//             printf(" ");
//         }

//         // 3rd LOOP FOR PRINTING STAR     (INORDER TO GET NUMBERS, REPLACE * with %d of j)

//         for(j= 0; j<= i; j++)
//         {
//             printf("%d ",j);
//         }
//     }
// */


// INVERTED PYRAMID

#include<stdio.h>
int main()
{
    int row, i, j, s;
    printf("\n Enter the rows required: ");
    scanf("%d", & row);

    // OUTER LOOP FOR NEW LINES                              

    for (i= row; i>= 1; i--)
    {
        printf("\n");

    // 2nd LOOP FOR PRINTING THE SPACES

        for(s= 1; s<= (row- i); s++)
        {
            printf(" ");
        }

    // 3rd LOOP FOR PRINTING STAR     (INORDER TO GET NUMBERS, REPLACE * with %d of j)

        for(j= i; j>= 1; j--)
        {
            printf("* ");
        }
    }
    return 0;
}
