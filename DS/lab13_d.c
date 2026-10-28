
#include <stdio.h>

int main() {
    int a[100], stack[200], n, i;
    int top = -1, low, high, p, j, t;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    stack[++top] = 0;
    stack[++top] = n - 1;

    while(top >= 0) {
        high = stack[top--];
        low = stack[top--];

        i = low;
        j = high;
        p = a[high];

        while(i < j) {
            while(i < j && a[i] <= p)
                i++;
            while(i < j && a[j] >= p)
                j--;

            if(i < j) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

        t = a[i];
        a[i] = a[high];
        a[high] = t;

        if(low < i-1) {
            stack[++top] = low;
            stack[++top] = i-1;
        }

        if(i+1 < high) {
            stack[++top] = i+1;
            stack[++top] = high;
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
