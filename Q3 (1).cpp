#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int n, i, j, mid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    mid = n / 2;

    printf("Output: ");

    for (i = 0, j = mid; i < mid; i++, j++)
    {
        printf("%d %d ", queue[i], queue[j]);
    }

    printf("\n");

    return 0;
}
