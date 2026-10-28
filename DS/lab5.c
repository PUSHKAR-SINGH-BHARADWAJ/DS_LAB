#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}
//PUSHKAR SINGH BHARADWAJ
void insertEnd()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
//2501920110288
    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}

void insertPos()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        insertBeg();
        return;
    }

    if(head == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp = head;
    for(i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if(i != pos - 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBeg()
{
    struct node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    last = head;
    while(last->next != head)
        last = last->next;

    temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}

void deleteEnd()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void deletePos()
{
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || head == NULL)
    {
        printf("Invalid position or empty list\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeg();
        return;
    }

    temp = head;
    for(i = 1; i < pos && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(i != pos)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

int main()
{
    int ch;

    do
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Any Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Any Position");
        printf("\n7. Display");
        printf("\n8. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertPos(); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: deletePos(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 8);

    return 0;
}