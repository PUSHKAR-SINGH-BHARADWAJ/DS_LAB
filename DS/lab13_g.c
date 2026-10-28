
#include <stdio.h>

int main() {
    int a[100], b[100], n, i, width;
    int left, mid, right, x, y, k;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(width = 1; width < n; width *= 2) {
        for(left = 0; left < n; left += 2*width) {
            mid = left + width;
            right = left + 2*width;

            if(mid > n) mid = n;
            if(right > n) right = n;

            x = left;
            y = mid;
            k = left;

            while(x < mid && y < right) {
                if(a[x] <= a[y])
                    b[k++] = a[x++];
                else
                    b[k++] = a[y++];
            }

            while(x < mid)
                b[k++] = a[x++];

            while(y < right)
                b[k++] = a[y++];

            for(i = left; i < right; i++)
                a[i] = b[i];
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
