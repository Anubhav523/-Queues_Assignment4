#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void push(int x)
{
    int i, temp;

    rear++;
    queue[rear] = x;

    for (i = front; i < rear; i++)
    {
        temp = queue[i];

        for (int j = i; j < rear; j++)
            queue[j] = queue[j + 1];

        queue[rear] = temp;
    }
}

void pop()
{
    if (rear < front)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped element: %d\n", queue[rear]);
        rear--;

        if (rear < front)
        {
            front = 0;
            rear = -1;
        }
    }
}

void display()
{
    int i;

    if (rear < front)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");

        for (i = rear; i >= front; i--)
            printf("%d ", queue[i]);

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
