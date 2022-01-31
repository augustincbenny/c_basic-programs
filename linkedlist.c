#include<stdio.h>
#include <stdlib.h>

void display();
void insertAtFront();
void insertAtEnd();
void insertAfterPosition();
void deleteAtFront();
void deleteAtEnd();
void deletePosition();

struct node
{
    int data;
    struct node *next;
};
// head pointer stores the address of the starting structure node
// newnode pointer stores the address of the new structure nodes created 
// temp pointer is used so that the addresses stored by the newnode pointer is not destroyed when multiple nodes are created
// initially the head pointer don't have any address
// head= 0 or NULL
struct node *head= 0, *newnode, *temp;
int count= 0;

void main()
{
    int choice= 1, opt;
    while(choice == 1)
    {
    /*  All the nodes have to created only when needed. We cannot specify how much memory is to be allocated in the begining 
        of the program. It needs to be dynamically allocated each time a node is created. This memory allocation is done by malloc.
        Malloc simply returns the staring address of the newly created structure node or memory block (here 4 + 4 bytes)
        ie; malloc(sizeof(struct node))  
        This newly created address is stored to a pointer variable called newnode pointer*/

        newnode= (struct node *) malloc(sizeof(struct node));

        printf("Enter the data: ");
        scanf("%d",& newnode-> data);
        newnode-> next= 0; /* Here we are giving 0 because this is the only node created and no node is created after this one in the present loop. 
                            Therefore the address of the newly created node is given null. */
   
        if (head == 0) 
            head= temp= newnode; /* This condition is only valid when a new structure node is created for the 1st time
                                    So the address of the newly created node (whic is obtained from malloc) is copied from the newnode 
                                    pointer to the head pointer and the temp pointer 
                                    Head pointer address remains fixed in the rest of the program.*/ 
        else
        {
            temp-> next= newnode; /*here the temp pointer refers to previous node's address and the 
                                    newnode's address gets copied to previous node's next*/ 
            temp= newnode; /*here the temp pointer address gets updated to the newnode pointer address
                            At the end of each loop, the address of temp pointer must be same as the address of the newnode pointer */
                            /*VIM*/
        }

        printf("Enter 1 to continue the input, else Enter 0\n");
        scanf("%d", & choice);
    }

    // Display list
    display();

    printf("\nOption 1: insertAtFront\nOption 2: insertAtEnd\nOption 3: insertAfterPosition\nOption 4: deleteAtFront\nOption 5: deleteAtEnd\nOption 6: deletePosition\n");
    printf("Enter the option number: ");
    scanf("%d", & opt);
    switch (opt)
    {
        case 1: insertAtFront();
                break;
        case 2: insertAtEnd();
                break;
        case 3: insertAfterPosition();
                break;
        case 4: deleteAtFront();
                break;
        case 5: deleteAtEnd();
                break;
        case 6: deletePosition();
                break;
        default: 
                printf("Invalid Option\n");
    }

    // Reset count to zero and Display
    count= 0;
    display();
}

void display()
{
    printf("List:\n");
    for (temp= head; temp!= 0; temp= temp-> next)   /*temp= 0, refers to the NULL node address after the last node in the list. 
                                                    So the loop stops before reaching the NULL node.
                                                    Here the list gets displayed but the final address of temp gets updated to NULL*/
    {
        printf("%d\n", temp-> data);
        count++;
    }
    printf("Total nodes=  %d", count);
}

void insertAtFront()
{
    newnode= (struct node *) malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", & newnode->data);
    newnode->next= head;
    head= newnode;
}

void insertAtEnd()
{
    newnode= (struct node *) malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", & newnode->data);
    newnode->next= 0;
    // traversing through list
    for(temp= head; temp->next!= 0; temp= temp->next); /*temp->next= 0 refers to the address stored in last node.
                                                        So the loop stops before reaching the last node, ie, it stops in 2nd last node.
                                                        However, finally, address of temp gets updated to last node's address*/
    temp->next= newnode;                                                    
}

void insertAfterPosition()
{
    int pos, i= 1;
    printf("Enter the position:");
    scanf("%d", & pos);
    if (pos > count)
        printf("Invalid position\n");
    else
    {
        newnode= (struct node *) malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", & newnode->data);
        for(temp= head; i< pos; temp= temp->next, i++); /*  So the loop stops before reaching the selected node, ie, it stops in previous node. 
                                                            However, finally, address of temp gets updated to selected node's address  */
        newnode->next= temp->next;
        temp->next= newnode;
    }
}

void deleteAtFront()
{
    if (head == 0)
        printf("The list is Empty.\n");
    else
    {
        temp= head; /*  Now temp, head as well as the 1st node to be  deleted have the same address.
                        So literally, 1st node->next= head->next= temp->next  */
        head= temp->next;
        free(temp); /*  Even though the link is detached form list, the memory of the node must be returned to the heap.
                        This is done by free function.  */
    }
}

void deleteAtEnd()
{
    // to do this we need 2 pointers
    // one pointer to traverse the list and point to the last node: *temp
    // another pointer to point to the 2nd last node: *prevnode
    struct node *prevnode;
    if (head == 0)
        printf("The list is Empty.\n");
    else
    {
        // traversing through list
        for(temp= head; temp->next!= 0; temp=temp->next)
            prevnode= temp;    /*Here the loop stops on reaching the 2nd last node. 
                                So the temp pointer inside the loop will have the address of 2nd last node
                                This address is copied to  prevnode pointer
                                However, later on in the update statement, temp gets updated to the last node's address. */

        //Sometimes, in the case of only 1 node, the above loop will not excecute. So there is no use of prevnode.
        // This condition will be same as deleteAtFront()
        if (temp == head)
            deleteAtFront();
        else
        {
            prevnode->next= 0;
            free(temp);
        }
    }
}

void deletePosition()
{
    struct node *prevnode;
    int pos, i= 1;
    printf("Enter the position:");
    scanf("%d", & pos);
    if (pos > count)
        printf("Invalid position\n");
    else if (head == 0)
        printf("The list is Empty.\n");
    else
    {
        for(temp= head; i< pos; temp= temp->next, i++)
            prevnode= temp;
        
        if (temp == head)
            deleteAtFront();
        else
        {
            prevnode->next= temp->next;
            free(temp);
        }
    }
}
