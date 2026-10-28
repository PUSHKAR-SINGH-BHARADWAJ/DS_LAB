#include <stdio.h>

int main()
{
    int a[100], n, key, i;

    printf("Enter size: ");
    scanf("%d", &n);
//pushkar singh bharadwaj
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element found at position %d", i + 1);
            return 0;
        }
    }
//2501920110288
    printf("Element not found");
    return 0;
}