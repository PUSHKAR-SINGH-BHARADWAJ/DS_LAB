
#include <stdio.h>

void display(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[100], n, i, ch, x;

    printf("Enter size: ");
    scanf("%d", &n);
//PUSHKAR SINGH BHARADWAJ
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1. Insert at Beginning");
    printf("\n2. Insert at End");
    printf("\n3. Delete from Beginning");
    printf("\n4. Delete from End");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
//2501920110288
    switch(ch)
    {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);

            for(i = n; i > 0; i--)
                a[i] = a[i - 1];

            a[0] = x;
            n++;
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &x);

            a[n] = x;
            n++;
            break;

        case 3:
            for(i = 0; i < n - 1; i++)
                a[i] = a[i + 1];

            n--;
            break;

        case 4:
            n--;
            break;

        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("Updated array: ");
    display(a, n);

    return 0;
}
