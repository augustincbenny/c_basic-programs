#include<stdio.h>
#include<stdlib.h>

int searchElement(int);
void display();
void insertAtFront();
void insertAtEnd();
void insertAfterElement();
void deleteAtFront();
void deleteAtEnd();
void deleteElement();

struct dllNode
{
    int data;
    struct dllNode *prev;
    struct dllNode *next;
};
struct dllNode *head= 0, *newnode, *temp;
int count= 0;

void main()
{
    int choice1= 1, choice2= 1, opt;

    while(choice1)
    {
        newnode= (struct dllNode *)malloc(sizeof(struct dllNode));
        printf("Enter the data:  ");
        scanf("%d", & newnode->data);
        newnode->prev= 0;
        newnode->next= 0;

        if (head == 0)
            head= temp= newnode; 
        else
        {
            temp->next= newnode;
            newnode->prev= temp;
            temp= newnode;
        }

        printf("Press 1 to continue the input, else Press 0:  ");
        scanf("%d", & choice1);       
    }

    // Display list
    display();

    while(choice2)
    {
        printf("\nOption 1: insertAtFront\nOption 2: insertAtEnd\nOption 3: insertAfterElement\nOption 4: deleteAtFront\nOption 5: deleteAtEnd\nOption 6: deleteElement\n");
        printf("Enter the option number: ");
        scanf("%d", & opt);
        switch (opt)
        {
            case 1: insertAtFront();
                    break;
            case 2: insertAtEnd();
                    break;
            case 3: insertAfterElement();
                    break;
            case 4: deleteAtFront();
                    break;
            case 5: deleteAtEnd();
                    break;
            case 6: deleteElement();
                    break;
            default: 
                    printf("Invalid option.\n");
        }
        printf("Press 1 to continue the operations, else Press 0:  ");
        scanf("%d", & choice2); 
    }

    // Reset count to zero and Display list
    count= 0;
    display();
}

void display()
{
    printf("List:\n");
    for(temp= head; temp!= 0; temp= temp->next)
    {
        printf("%d\n", temp->data);
        count++;
    }
    printf("Total nodes=  %d", count);
}

int searchElement(int y)
{
    for(temp= head; temp!= 0; temp= temp->next)
    {
        if (temp->data == y)
            return 1;
    }
    return 0;
}

void insertAtFront()
{
    newnode= (struct dllNode *)malloc(sizeof(struct dllNode));
    printf("Enter the data:");
    scanf("%d", & newnode->data);
    newnode->next= head;
    head->prev= newnode;
    head= newnode;
}

void insertAtEnd()
{
    if(head == 0)
        printf("The list is empty. Insertion failed\n");
    else
    {
        newnode= (struct dllNode *)malloc(sizeof(struct dllNode));
        printf("Enter the data:");
        scanf("%d", & newnode->data);
        newnode->next=0;
        for(temp= head; temp->next!= 0; temp= temp->next);
        temp->next= newnode;
        newnode->prev= temp;
    }
}

void insertAfterElement()
{
    int z, result;
    if(head == 0)
        printf("The list is empty. Insertion failed\n");
    else
    {
        printf("Enter the element to be searched: ");
        scanf("%d", & z);
        result= searchElement(z);
        if (result == 0)
            printf("Element not found. Insertion failed\n");
        else
        {
            newnode= (struct dllNode *)malloc(sizeof(struct dllNode));
            printf("Enter the data:");
            scanf("%d", & newnode->data);
            newnode->next= temp->next;
            temp->next= newnode;
            newnode->prev= temp;
            // we want to access the next node after the newly inserted newnode and change its prev pointer
            // But this should happen only if the newnode created wasn't the last node in the list
            if (newnode->next != 0)
                newnode->next->prev= newnode; 
        }
    }
}

void deleteAtFront()
{
    if(head == 0)
        printf("The list is empty. Deletion Unsuccessful\n");
    else
    {
        temp= head;
        head= temp->next; 
        // head->prev= 0; /* This statment must be done logically, but there are issues */
        free(temp);
    }
}

void deleteAtEnd()
{
    struct dllNode *prevnode;
    if (head == 0)
        printf("The list is Empty. Deletion Unsuccessful\n");
    else 
    {
        for (temp= head; temp->next!= 0; temp= temp->next)
            prevnode= temp; /* prevnode is used to obtain the address of the 2nd last node */
        if (temp == head) /* This condition checks if there is only one node in the list */
            deleteAtFront();
        else
        {
            prevnode->next= 0;
            free(temp);
        }
    }
}

void deleteElement()
{
    struct dllNode *prevnode;
    int x, result;
    if (head == 0)
        printf("The list is empty. Deletion Unsuccessful\n");
    else
    {
        printf("Enter the element to be deleted: ");
        scanf("%d", & x);
        result= searchElement(x);
        if(result == 0)
            printf("Element not found. Deletion Unsuccessful\n");
        else if (head == temp) /* This condition checks if there is only one node in the list */
            deleteAtFront();
        else
        {
            prevnode= temp->prev; /* prevnode is used to obtain the address of the 2nd last node */
            prevnode->next= temp->next;

            // we want to access the next node after the current deleted temp node and change its prev pointer
            // But this should happen only if the newnode created wasn't the last node in the list
            if (temp->next != 0)
                temp->next->prev= prevnode;
            free(temp);
        }
    }
}
