#include<stdio.h>
#include<conio.h>

void main(){
  int arr[20],size,i,data;

  printf("Enter size of the list: ");
  scanf("%d",&size);

  printf("Enter any %d integer values: ",size);
  for(i = 0; i < size; i++)
    scanf("%d",&arr[i]);

  printf("Enter the element to be Search: ");
  scanf("%d",&data);
  
  for(i = 0; i < size; i++)
  {
     if(data == arr[i])
     {
        printf("Element is found at %d index", i);
        printf("Element is found at %d position", i+1);

        break;
     }
  }
  if(i == size)
     printf("Given element is not found in the list!!!");
  getch();
}
