#include <stdio.h>
#include <string.h>
#define MAX 500

typedef struct Queue {
   int front;
   int rear;
   int queue[MAX];

}Queue;


void init(Queue *q) {
   q->front = 0;
   q->rear = 0;
}


int is_empty(Queue *q) {
   if (q->front == q->rear)
      return 1;
   return 0;
}


int is_full(Queue *q) {
   if ((q->rear + 1) % MAX == q->front)
      return 1;
   return 0;
}


int push(Queue *q, int item) {
   if (is_full(q)) {
      printf("Full\n");
      return -1;
   }
   q->rear = (q->rear + 1) % MAX;
   return q->queue[q->rear] = item;
}


int pop(Queue *q) {
   if (is_empty(q)) {
      return -1;
   }
   q->front = (q->front + 1) % MAX;
   return q->queue[q->front];
}

int size(Queue *q) {
   return q->rear - q->front;
}

int front(Queue *q) {
	if (is_empty(q))
		return -1;
	return q->queue[q->front + 1];
}

int back(Queue *q) {
	if (is_empty(q))
		return -1;
	return q->queue[q->rear];
}

  
int main() {
   Queue q;
   init(&q);
   char str[MAX];
   int num;
   int sum = 0;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {

        scanf("%s", str);
        if (!strcmp(str, "push")) {
            scanf("%d", &sum);
            push(&q, sum);
        }
        else if (!strcmp(str, "empty"))
            printf("%d\n", is_empty(&q));
            
        else if (!strcmp(str, "pop"))
            printf("%d\n", pop(&q));
            
        else if (!strcmp(str, "size"))
            printf("%d\n", size(&q));
            
        else if (!strcmp(str, "front"))
            printf("%d\n", front(&q));
            
        else if (!strcmp(str, "back"))
            printf("%d\n", back(&q));
    }
    return 0;
}
