
#include <stdio.h>

int main() {
    int a[100], b[100], n, i, exp, max = 0;
    int count[10], digit;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > max)
            max = a[i];
    }

    for(exp = 1; max/exp > 0; exp *= 10) {
        for(i = 0; i < 10; i++)
            count[i] = 0;

        for(i = 0; i < n; i++)
            count[(a[i]/exp)%10]++;

        for(i = 1; i < 10; i++)
            count[i] += count[i-1];

        for(i = n-1; i >= 0; i--) {
            digit = (a[i]/exp)%10;
            b[--count[digit]] = a[i];
        }

        for(i = 0; i < n; i++)
            a[i] = b[i];
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
