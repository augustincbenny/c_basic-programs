#include<stdio.h>
int main()
{
    int num,cpy_num,rem=0,sum=0;
    printf("Enter a three digit armstrong number:");
    scanf("%d",&num);
    cpy_num=num;

    for( ;num!=0; num= num/10)
    {
        rem=num%10;                  
        sum=sum+(rem*rem*rem);
    }

    // USING WHILE LOOP
    // while (num != 0){
    //     rem = num % 10;
    //     sum = sum + (rem*rem*rem) ;               
    //     num = num / 10;
    // }
    
    if (cpy_num==sum)
        printf("The given number is an 3 digit Armstrong nunmber.");
    else
    {
        printf("The given number is not an 3 digit Armstrong number.");
    }
    return 0;    
}
