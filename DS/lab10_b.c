#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        struct node *temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

void display()
{
    struct node *temp = front;

    if (temp == NULL)
        printf("Queue is empty\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch, x;
    do
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);

    return 0;
}