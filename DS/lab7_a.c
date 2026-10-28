
#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push() {
    int x;
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        printf("Enter value: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}
//PUSHKAR SINGH BHARADWAJ
void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted: %d\n", stack[top--]);
}
//2501920110288
void display() {
    int i;
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int ch;
    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
