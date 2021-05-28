#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void peep();
void display();
struct stack
{
    int size;
    int top;
    int *arr;
};
struct stack *s;
int main()
{
    int choice;
    s = (struct stack *)malloc(sizeof(struct stack));
    printf("\nEnter the size of the stack");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    while (1)
    {
        printf("\nEnter 1 to push");
        printf("\nEnter 2 to pop");
        printf("\nEnter 3 to display");
        printf("\nEnter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
void push()
{
    int item;
    if (s->top == s->size - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter the element ");
        scanf("%d", &item);
        s->top++;
        s->arr[s->top] = item;
    }
}
void pop()
{
    int item;
    if (s->top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        item = s->arr[s->top];
        s->top--;
        printf("\nThe popped Value is : %d", item);
    }
}
void peep()
{
    if (s->top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("The peeped value is : %d", s->arr[s->top]);
    }
}
void display()
{
    int i;
    if (s->top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        for (i = s->top; i >= 0; i--)
        {
            printf("\n%d", s->arr[i]);
        }
    }
}