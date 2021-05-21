#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


typedef struct Stack{
	int arr[SIZE];
	int top; // 스택 요소 개수
	
	 
}Stack;

void init(Stack *s) {
 	s->top = -1;
}

int is_full(Stack *s) {
	if(s->top == SIZE - 1)
		return 1;
	return 0;
}

int is_empty(Stack *s) {
	if(s->top == -1)
		return 1;
	return 0;
}

void push(Stack *s, int value) {
	if(is_full(s)) {
		printf("Stack is full / Error");
		exit(1);
	}
	s->arr[++(s->top)] = value;
	
}	

int pop(Stack *s) {
	if(is_empty(s)) {
		printf("Stack is empty / Error");
		exit(1);
	}
	return s->arr[(s->top--)];
}

int peek(Stack *s) {
	if(is_empty(s)) {
		printf("Stack is empty / Error");
		exit(1);
	} 
	return s->arr[(s->top)];
}

int main(int argc, const char * argv[]) {
	Stack s;
	init(&s);
	push(&s, 906);
	push(&s, 218);
	push(&s, 613);
	push(&s, 713);
	
	printf("peek : %d", peek(&s));
	for(int i =0; i < 4; i++) {
		printf("pop : %d\n", pop(&s));
	}
}
