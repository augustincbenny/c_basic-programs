#include<stdio.h>
#include<stdlib.h>
#define Maxsize 20


void push();
void pop();
void display();

int top= -1, stack[Maxsize];
int main()
{
	int option;
	while(1)
	{
		printf("\nOption 1: Push\nOption 2: Pop\nOption 3: display\nOption 4: Exit\n");
		printf("Enter the option number: ");
		scanf("%d", & option);
		switch(option)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			default:
					printf("Invalid option. Try again\n");
					
		}
	}
}
	
void push()
{
	int x;
	if (top == Maxsize- 1)
		printf("The stack is full.\n");
	else
	{
		printf("Enter the number: ");
		scanf("%d", & x);
		top++;
		stack[top]= x;
	}
}

void pop()
{
	if (top ==- 1)
		printf("The stack is empty.\n");
	else
	{
		printf("Popped element: %d\n\n", stack[top]);
		top--;
	}
}

void display()
{
	if (top ==- 1)
		printf("The stack is empty.\n");
	else
	{
		printf("Stack: \n");
		for(int i= top; i>= 0; i--)
			printf("%d\n", stack[i]);
	}
}
