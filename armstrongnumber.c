#include<stdio.h>
#include<math.h>
int main()
{
    int num, cpy_num, rem, n, sum = 0;
    printf("Enter number:\n");
    scanf("%d", & num);
    cpy_num = num;

// Counting the number of digits in num

    for(n= 0; num != 0; n++)
    {
        num=num/ 10;
    }

// To find the square using pow function

    num= cpy_num;   /* we are writing this line because the value of num was changed in above forloop */
    while (num != 0)
    {
        rem = num % 10;
        sum = sum + pow(rem, n);               
        num = num / 10;
    }

    // //  Using for loop

    // for (num = cpy_num; num != 0; num = num / 10) {
    //     rem = num % 10;
    //     sum = sum + pow(rem, n);
    // }


    if ((int)sum == cpy_num)
        printf("The given number is an Armstrong number.");
    else
        printf("The given number is not an Armstrong number.");
    return 0;   
}
