#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct Queue {
    int data[100];
    int rear;
    int front;
    int item;
} Queue;

void init(Queue *q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(Queue *q) {
	return (q->front == q->rear);
}

int is_full(Queue *q) {
	return (q->rear+1 % MAX_QUEUE_SIZE == q->front);
}

int enqueue(Queue *q, int item) {
	if(is_full(q)) {

		printf("full");
		exit(1); }
	else
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	printf("front = %d, rear = %d\n", q->front, q->rear);
}

int dequeue(Queue *q) {
	if(is_empty(q)) {
	
		printf("empty");
		exit(1);
	}
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	
	printf("front = %d, rear = %d\n", q->front, q->rear);
	return q->data[q->front];
}

int main(void) {
	Queue q;
	init(&q);
	
	for(int i = 0; i < 3; i++) {
	enqueue(&q, 3);
	}
	for(int i = 0; i < 3; i++) {
	dequeue(&q);
	}
	
	return 0;
}

