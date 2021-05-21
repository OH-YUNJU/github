#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int main() {
	Stack s;
	char str[SIZE];
	char str1[SIZE];
	int i, n, k = 0;
	init(&s);
	
	printf("문자열을 입력하시오: ");
	gets(str);
	
	for (i = 0; i < strlen(str); i++) {
		if(isupper(str[i]))
			str[i] += 32;
	}
	
	for (i = 0; i < strlen(str); i++) {
			push(&s, str[i]);
		if (isspace(str[i]))
			pop(&s);	
	}
	

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == pop(&s))
            return printf("회문입니다.");
		else
			return printf("회문이 아닙니다.");             
	}
		
}
