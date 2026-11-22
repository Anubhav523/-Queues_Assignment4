#include <stdio.h>

#define MAX 100

int main()
{
    char str[MAX];
    char queue[MAX];
    int count[256] = {0};
    int front = 0, rear = -1;
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        count[(unsigned char)str[i]]++;
        rear++;
        queue[rear] = str[i];

        while (front <= rear && count[(unsigned char)queue[front]] > 1)
            front++;

        if (front <= rear)
            printf("%c ", queue[front]);
        else
            printf("-1 ");
    }

    return 0;
}
