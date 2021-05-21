#include <stdio.h>
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


int equeue(Queue *q, int item) {
   if (is_full(q)) {
      printf("full");
      
      return 0;
   }
   q->rear = (q->rear + 1) % MAX;
   return q->queue[q->rear] = item;
}


int dequeue(Queue *q) {
   if (is_empty(q)) {
      printf("empty");
      
      return 0;
   }
   q->front = (q->front + 1) % MAX;
   return q->queue[q->front];
}

int size(Queue *q) {
   return q->rear - q->front;
}

int card(Queue *q, int num) {
   
   for (int i = 1; i <= num; i++) {
      equeue(q, i);
   }
   while (size(q) != 1) {
      dequeue(q);
      equeue(q, dequeue(q));
   }
   return dequeue(q);

}

int main() {
   Queue q;
   init(&q);
   
   int sum;

   scanf("%d", &sum);
   printf("%d", card(&q, sum));
}

