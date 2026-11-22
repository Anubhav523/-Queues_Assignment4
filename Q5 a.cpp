#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

void push(int x)
{
    int temp;

    r2++;
    q2[r2] = x;

    while (f1 <= r1)
    {
        temp = q1[f1];
        f1++;

        r2++;
        q2[r2] = temp;
    }

    f1 = 0;
    r1 = -1;

    while (f2 <= r2)
    {
        temp = q2[f2];
        f2++;

        r1++;
        q1[r1] = temp;
    }

    f2 = 0;
    r2 = -1;
}

void pop()
{
    if (f1 > r1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped element: %d\n", q1[f1]);
        f1++;

        if (f1 > r1)
        {
            f1 = 0;
            r1 = -1;
        }
    }
}

void display()
{
    int i;

    if (f1 > r1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");

        for (i = f1; i <= r1; i++)
            printf("%d ", q1[i]);

        printf("\n");
    }
}

int main()
{
    int choice, x;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Wrong choice\n");
        }

    } while (choice != 4);

    return 0;
}
