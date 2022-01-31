#include<stdio.h>
#include<stdlib.h>

int Maxsize; 

void enqueue(int);
void dequeue();
void peek();
int isEmpty();
int isFull();
void display();

int rear= -1, front= -1, *queue; 
//This is the initial condition for an empty queue. both will be -1  
// Insertion only happens through rear and at this time only rear changes; front remains constant and viceversa
// Thus the queue is empty when (rear= front= -1) and full when (rear= Maxsize-1)
// Sometimes front= rear (not -1). This is the condition if there is only one element in the queue
// So it is necessary to reset the front and rear back to -1 during the dequeue 

int main()
{
    int option, x;
    printf("Enter the size of queue: ");
    scanf("%d", & Maxsize);
    queue= (int *) malloc(sizeof(int) * Maxsize);
    while(1)
    {
        while(1)
	{
		printf("\nOption 1: enqueue()\nOption 2: dequeue()\nOption 3: peek()\nOption 4: display()\nOption 5: exit()\n");
		printf("Enter the option number: ");
		scanf("%d", & option);
		switch(option)
		{
			case 1: printf("Enter the number:");
					scanf("%d",& x);
					enqueue(x);
					break;
			case 2: dequeue();
					break;
			case 3: peek();
					break;
			case 4: display();
					break;
			case 5: exit(0);
			default:
					printf("Invalid option. Try again\n");
		}
	}
	return 0;
    }
}

int isFull()
{
    return(rear == Maxsize- 1);
}

int isEmpty()
{
    return((front == -1) && (rear == -1));
}

void enqueue(int y)
{
    if (isFull())
        printf("OverFlow!!\n");
    else if (isEmpty())
    {
        front= rear= 0;
        queue[rear]= y;
        printf("Inserted element: %d\n", y);
    }
    else
    { 
        rear++; 
        queue[rear]= y;
        printf("Enqueued element: %d\n", y);
    }
}

void dequeue()
{
    if (isEmpty())
        printf("Underflow!!\n");
    else if (front == rear) // This condition is done to reset the front and rear back to -1 if there was only one element remaining.  
    {
        printf("Dequeued element: %d\n", queue[front]);
        front= rear= -1;
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void peek()
{
    if (!isEmpty())
        printf("Peeked element: %d\n", queue[front]);
}

void display()
{
    if (isEmpty())
        printf("The queue is empty.\n");
    else
    {
        printf("Queue:\n");
        for(int i= front; i<= rear ; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}
