#include<stdio.h>
#include<conio.h>
void main()
{
    int n, i, j, temp=0;
    printf("\nEnter number of elements: ");
    scanf("%d", & n);
    int num[n];
    printf("Enter the list of elements: \n");

    // ENTER LOOP

    for(i= 1; i<= n; i++)
    {
        scanf("%d", & num[i]);
    }

    // RETURN LOOP ANALYSING
    
    for(i= 1; i<= n; i++)
    {
        for (j= i; j<= n; j++)
        {
            if(num[i] >= num[j])
            {
                temp= num[i];
                num[i]= num[j];
                num[j]= temp;
            }
        }
    }

    // RETURN LOOP PRINTING

    printf("The list of elements in asending order is: \n");
    for(i= 1; i <= n; i++) 
    {   
        printf("%d \n", num[i]);  
    }  
    getch();
}
