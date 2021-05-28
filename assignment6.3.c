#include <stdlib.h>
#include <stdio.h>
void insert();
void delete ();
void display();
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
struct queue *s;
int main()
{
    int choice;
    s = (struct queue *)malloc(sizeof(struct queue));
    printf("enter the size of the queue");
    scanf("%d", &s->size);
    s->front = -1;
    s->rear = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    while (1)
    {
        printf("\n Enter 1 to insert");
        printf("\n Enter 2 to delete");
        printf("\n Enter 3 to display");
        printf("\n Enter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice");
            break;
        }
    }
}
void insert()
{
    int item;
    if (s->rear == s->size - 1 && s->front == 0 || s->front == s->rear + 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        printf("Enter the item :\t");
        scanf("%d", &item);
        if (s->front == -1)
        {
            s->rear = 0;
            s->front = 0;
        }
        else if (s->rear == s->size - 1)
        {
            s->rear = 0;
        }
        else
        {
            s->rear++;
        }
        s->arr[s->rear] = item;
    }
}
void delete ()
{
    int item;
    if (s->front == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        item = s->arr[s->front];
        printf("The deleted value is : %d", item);
        if (s->front == s->rear)
        {
            s->rear = -1;
            s->front = -1;
        }
        else
        {
            if (s->front == s->size - 1)
            {
                s->front = 0;
            }
            else
                s->front++;
        }
    }
}
void display()
{
    int i;
    int frontl, rearl;
    frontl = s->front;
    rearl = s->rear;
    if (frontl == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        if (frontl < rearl)
            while (frontl <= rearl)
            {
                printf("%d\n", s->arr[frontl]);
                frontl++;
            }
        else
        {

            while (frontl <= s->size - 1)
            {
                printf("%d\n", s->arr[frontl]);
                frontl++;
            }
            frontl = 0;
            while (frontl <= rearl)
            {
                printf("%d\n", s->arr[frontl]);
                frontl++;
            }
        }
    }
}
