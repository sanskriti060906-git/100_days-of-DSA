//Implement a Min Heap using an array where the smallest element is always at the root.

#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void insert(int x){
    heap[size]=x;
    int i=size;
    size++;
    while(i>0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
int peek(){
    if(size==0) return -1;
    return heap[0];
}
int extractMin(){
    if(size==0) return -1;
    int min=heap[0];
    heap[0]=heap[size-1];
    size--;
    int i=0;
    while(2*i+1 < size){
        int left=2*i+1, right=2*i+2, small=left;
        if(right<size && heap[right]<heap[left])
            small=right;
        if(heap[i] > heap[small]){
            swap(&heap[i], &heap[small]);
            i=small;
        } else break;
    }
    return min;
}
int main(){
    int n,x;
    char op[20];
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
        else if(strcmp(op,"extractMin")==0){
            printf("%d\n",extractMin());
        }
    }
}
