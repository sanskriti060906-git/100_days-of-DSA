//Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#include <string.h>

int a[1000];
int n = 0;
void insert(int x)
{
    int i = n - 1;
    while(i >= 0 && a[i] > x)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = x;
    n++;
}
int delete()
{
    if(n == 0) return -1;
    int x = a[0];
    for(int i = 1; i < n; i++)
        a[i - 1] = a[i];
    n--;
    return x;
}
int peek()
{
    if(n == 0) return -1;
    return a[0];
}
int main()
{
    int t, x;
    char s[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        if(strcmp(s,"insert") == 0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(s,"delete") == 0)
        {
            printf("%d\n",delete());
        }
        else if(strcmp(s,"peek") == 0)
        {
            printf("%d\n",peek());
        }
    }
}
