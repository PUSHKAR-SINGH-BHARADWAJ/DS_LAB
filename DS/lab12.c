#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int key)
{
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
        if (index == start)
        {
            printf("Hash Table Full\n");
            return;
        }
    }

    hashTable[index] = key;
}
//PUSHKAR SINGH BHARADWAJ
void display()
{
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d -> Empty\n", i);
        else
            printf("%d -> %d\n", i, hashTable[i]);
    }
}
//2501920110288
int main()
{
    int i, n, key;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}