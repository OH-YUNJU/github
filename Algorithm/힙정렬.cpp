#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType *h)
{
    h->heap_size = 0;
}

void insert(HeapType *h, element item)
{
    int index;
    index = ++(h->heap_size);
    
    while((index != 1) && (item.key > h->heap[index/2].key))
    {
        h->heap[index] = h->heap[index/2];
        index /= 2;
    }
    
    h->heap[index] = item; //insert new node
}

element delete(HeapType *h)
{
    int parent, child;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size)
    {
        if((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if(temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(int argc, const char * argv[]) {
    
    element e1 = {10}, e2 = {5}, e3 = {30};
    element e4, e5, e6;
    HeapType *heap;
    
    heap = create();
    init(heap);
    
    insert(heap, e1);
    insert(heap, e2);
    insert(heap, e3);

    e4 = delete(heap);
    printf("<%d>\n", e4);
    
    e5 = delete(heap);
    printf("<%d>\n", e5);
    
    return 0;
}

