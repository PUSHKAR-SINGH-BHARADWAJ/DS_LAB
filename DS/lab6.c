
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int c, e;
    struct Node *next;
};

struct Node* create(int c, int e) {
    struct Node *n = malloc(sizeof(struct Node));
    n->c = c;
    n->e = e;
    n->next = NULL;
    return n;
}

struct Node* input() {
    struct Node *head = NULL, *temp = NULL, *n;
    int i, count, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);
        n = create(c, e);

        if (head == NULL)
            head = n;
        else
            temp->next = n;
        temp = n;
    }
    return head;
}
//PUSHKAR SINGH BHARADWAJ
struct Node* add(struct Node *p, struct Node *q) {
    struct Node *r = NULL, **t = &r;

    while (p && q) {
        int c, e;

        if (p->e == q->e) {
            c = p->c + q->c; e = p->e;
            p = p->next; q = q->next;
        } else if (p->e > q->e) {
            c = p->c; e = p->e; p = p->next;
        } else {
            c = q->c; e = q->e; q = q->next;
        }

        *t = create(c, e);
        t = &((*t)->next);
    }
    *t = p ? p : q;
    return r;
}
//2501920110288
void display(struct Node *p) {
    while (p) {
        printf("%dx^%d", p->c, p->e);
        p = p->next;
        if (p) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *p, *q, *r;

    printf("First polynomial:\n");
    p = input();

    printf("Second polynomial:\n");
    q = input();

    r = add(p, q);

    printf("Sum: ");
    display(r);

    return 0;
}
