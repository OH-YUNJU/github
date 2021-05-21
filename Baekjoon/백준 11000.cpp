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
	//printf("front = %d, rear = %d\n", q->front, q->rear);
}

int dequeue(Queue *q) {
	if(is_empty(q)) {
	
		printf("empty");
		exit(1);
	}
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	
	//printf("front = %d, rear = %d\n", q->front, q->rear);
	return q->data[q->front];
}

int class_room(Queue *q, int item) {
	int num1, num2;
	int cnt = 1;
	
	int tmp = num2 - 1;
	
	for(int i = 0; i < item; i++) {
		scanf("%d %d", &num1, &num2);
		
		if(is_empty(q)) {
			enqueue(q, num2);
			printf("%d %d",q->front, q->rear);
		}
		
		else if(q->front > num1) {
			enqueue(q, num2);
			cnt++;
		}
			
		else if(q->front+num2 <= num1) {
			enqueue(q, num2);
		}
		
		else {
			printf("다시 입력"); 
		}
	}
	
	printf("%d", cnt); 
}

int main(void) {
	Queue q;
	init(&q);
	
	int c;

	scanf("%d", &c);
	
	class_room(&q, c);
	
	return 0;
}

