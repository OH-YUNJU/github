#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

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
	}
	s->arr[++(s->top)] = value;
	
}	

int pop(Stack *s) {
	if(is_empty(s)) {
		return -1;
	}
	return s->arr[(s->top--)];
}

int peek(Stack *s) {
	if(is_empty(s)) {
		return -1;
	} 
	return s->arr[(s->top)];
}

int size(Stack *s) {
	return s->top + 1;
}

int main(int argc, const char * argv[]) {
	int n, i, j;
	Stack s;
	char num[10];
	init(&s);
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
        scanf("%s", num);
        
        if(strcmp(num, "push") == 0){
            scanf("%d", &j);
            push(&s, j);
    	}
        else if(strcmp(num, "size") == 0) {
			printf("%d\n", size(&s));
		}
		else if(strcmp(num, "empty") == 0) {
			printf("%d\n", is_empty(&s));
		}
		else if(strcmp(num, "top") == 0)
			printf("%d\n", peek(&s));
		else {
			printf("%d\n", pop(&s));
		}
      
    }
	return 0;
}
