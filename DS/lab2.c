#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int n, r1, c1, r2, c2;
    int i, j, k, sum1 = 0, sum2 = 0, diff;

    // Difference of diagonal sums
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        sum1 += a[i][i];
        sum2 += a[i][n - 1 - i];
    }

    diff = sum1 - sum2;

    printf("Primary diagonal sum = %d\n", sum1);
    printf("Secondary diagonal sum = %d\n", sum2);
    printf("Difference = %d\n", diff);

    // Multiplication of two matrices
    printf("\nEnter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    if(c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter first matrix elements:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Enter second matrix elements:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
//PUSHKAR SINGH BHARADWAJ
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            c[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                c[i][j] += b[i][k] * a[k][j];
            }
        }
    }

    printf("Product of two matrices:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
//2501920110288S
    return 0;
}
