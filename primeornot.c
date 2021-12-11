#include <stdio.h>

// Here statment 0 = prime    (this program can be easily done by try and accept statement in python)
// statment 1 = nonprime 

// Initially we are assigning all the statments to be prime

int main() 
{
  int n, i, stat = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

          // condition for non-prime

  for (i = 2; i <= n/2 ; i++) 
  {  
    //   or sqrt(n)
    if (n % i == 0) 
    {
      stat = 1;
      break;
    }
  }

  if (n == 1) 
    printf("1 is neither prime nor composite.");
  else 
  {
    if(stat == 1){
      printf("%d is a composite number.", n);
    }
    else
      printf("%d is prime number.", n);
  }
  return 0;
}
