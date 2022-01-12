/* X  x  y
   p  x  q
   Condition to check: y = p
   Product dimension: X x q
*/

#include<stdio.h> 
#define N 10   
int main()
{  
    int a [N][N], b [N][N], mul [N][N], x, y, p, q, i, j, k;    
    printf("\nEnter the number of rows of 1st matrix:");    
    scanf("%d", & x);    
    printf("Enter the number of columns of 1st matrix:");    
    scanf("%d", & y);

    printf("\nEnter the number of rows of 2nd matrix:");    
    scanf("%d", & p);    
    printf("Enter the number of columns of 2nd matrix:");    
    scanf("%d", & q);
    
    if(y != p)
    {
        printf("\nMatrix multiplication is not possible.");
        return 0;
    }

    printf("Enter elements of 1st Matrix:\n");
    for(i= 0; i< x; i++)    
    {    
        for(j= 0; j< y; j++)     
            scanf("%d", & a [i][j]);        
    }    
    
     printf("Enter elements of 2nd Matrix:\n");
    for(i= 0; i< p; i++)    
    {    
        for(j= 0; j< q; j++)    
            scanf("%d", & b [i][j]);    
    }    
    
    /* Here we are including another variable K and its for loop because, its value changes in each and every case
       eg: a[0][0]+b[0][0]      a[0][1]+b[1][0]
       The range of k value is upto the Condition to Check value
    */

    printf("\nThe product of the matrices are:\n");    
    for(i= 0; i< x; i++)    
    {    
        for(j= 0; j< q; j++)    
        {    
            mul[i][j] = 0;     
            for(k= 0; k< y; k++)    /*we can also write k< p*/  
                mul[i][j] += a [i][k] * b [k][j];
            printf("%d\t", mul [i][j]);
        }       
        printf("\n"); 
    }   
    
//     // The new row is X and the new column is q
//     for(i= 0; i< x; i++)    
//     {    
//         for(j= 0; j< q; j++)    
//             printf("%d\t", mul [i][j]);     
//         printf("\n");    
//     }    
//     return 0;  
// }  
