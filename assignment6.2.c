#include <stdio.h>
#include <stdlib.h>
void insert();
void delete ();
void display();
struct queue
{
    int size;
    int rear;
    int front;
    int *arr;
};
struct queue *s;
int main()
{
    int choice;
    s=(struct queue*)malloc(sizeof(struct queue));
    printf("enter the size of the queue");
    scanf("%d", &s->size);
    s->rear=-1;
    s->front=-1;
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
        printf("\nWrong Choice");
            break;
        }
    }
}
void insert()
{
    int item;
    if (s->rear == s->size - 1)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnter the element:");
        scanf("%d", &item);
        if (s->rear == -1)
        {
            s->rear++;
            s->front++;
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
    if (s->rear == -1 || s->front == s->rear + 1)
    {
        printf("\nqueue underflow");
    }
    else
    {
        item = s->arr[s->front];
        s->front++;
        printf("\nThe deleted value is : %d", item);
    }
}
void display()
{
    int i;
    if (s->rear == -1 || s->front == s->rear + 1)
    {
        printf("\nqueue underflow");
    }
    else
    {
        for (i = s->front; i <= s->rear; i++)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}