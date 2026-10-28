#include <stdio.h>
#define MAX 100

int q[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}
//PUSHKAR SINGH BHARADWAJ
void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("Deleted: %d\n", q[front++]);
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}
//2501920110288
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