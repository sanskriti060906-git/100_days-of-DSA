//Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
  #include <stdlib.h>

int cmp(const void* a, const void* b) {
    return ((int**)a)[0][0] - ((int**)b)[0][0];
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyUp(int* heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}
void heapifyDown(int* heap, int size, int i) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}
void push(int* heap, int* size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}
int pop(int* heap, int* size) {
    int top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return top;
}
int top(int* heap) {
    return heap[0];
}
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int size = 0;
    push(heap, &size, intervals[0][1]);
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= top(heap)) pop(heap, &size);
        push(heap, &size, intervals[i][1]);
    }
    int result = size;
    free(heap);
    return result;
}
