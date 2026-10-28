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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
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

    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
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
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
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

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
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
//PUSHKAR SINGH BHARADWAJ
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
//2501920110288
void display()
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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