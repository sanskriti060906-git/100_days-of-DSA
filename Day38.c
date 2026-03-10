//Deque (Double-Ended Queue)
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;
void push_front(int x)
{
    if(front == 0)
        printf("Overflow\n");
    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else
        deque[--front] = x;
}
void push_back(int x)
{
    if(rear == MAX-1)
        printf("Overflow\n");
    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else
        deque[++rear] = x;
}
void pop_front()
{
    if(front == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        front++;
}
void pop_back()
{
    if(rear == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        rear--;
}
int getFront()
{
    if(front == -1) return -1;
    return deque[front];
}
int getBack()
{
    if(rear == -1) return -1;
    return deque[rear];
}
int size()
{
    if(front == -1) return 0;
    return rear - front + 1;
}
int empty()
{
    return front == -1;
}
void display()
{
    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}
int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    display();
    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());
    pop_front();
    pop_back();
    display();
    return 0;
}
