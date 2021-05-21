#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct StackType {
    double arr[SIZE]; //int형 데이터 100개
   	int top;
} StackType;

void init(StackType *s)
{
    s->top = -1; //배열은 index 0부터 시작
}

//empty : return 1
//!empty : return 0
double is_empty(StackType *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

//full : return 1
//!full : return 0
double is_full(StackType *s)
{
    if(s->top == SIZE - 1)
        return 1;
    return 0;
}

void push(StackType *s, double value)
{
    if(is_full(s))
    {
        printf("Stack is full");
        //exit(1);
    }
    s->arr[++(s->top)] = value;
}

double pop(StackType *s)
{
    if(is_empty(s))
    {
        printf("Stack is empty");
        //exit(1);
    }
    return s->arr[(s->top)--];
}

double peek(StackType *s)
{
    /*if(is_empty(s))
    {
        printf("Stack is empty");
        //exit(1);
    }*/
    return s->arr[(s->top)];
}

int main() {
	StackType s;
    init(&s);
    
	char str[SIZE];
	//char ch;
    double arr[26];
	int n, k;
	double a, b;
	
	scanf("%d", &n);
		
	scanf("%s", str);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		arr[i] = k;
	}
		
	for (int i = 0; str[i] != NULL; i++) {
		if (str[i] == '+') {
			b = pop(&s);
			a = pop(&s);
			push(&s, a + b);
		}
		else if (str[i] == '-') {
			b = pop(&s);
			a = pop(&s);
			push(&s, a - b);
		}
		else if (str[i] == '*') {
			b = pop(&s);
			a = pop(&s);
			push(&s, a * b);
		}
		else if (str[i] == '/') {
			b = pop(&s);
			a = pop(&s);
			push(&s, a / b);
		}
		else {
			push(&s, arr[str[i]-'A']);
		}
	}
	/*for (int i = 0; str[i] != NULL; i++) {
		//ch = str[i];
		switch(str[i]) {
			case '+':
				b = pop(&s);
				a = pop(&s);
				push(&s, a + b);
			case '-':
				b = pop(&s);
				a = pop(&s);
				push(&s, a - b);
			case '*':
				b = pop(&s);
				a = pop(&s);
				push(&s, a * b);
			case '/':
				b = pop(&s);
				a = pop(&s);
				push(&s, a / b);
			default:
				push(&s, arr[str[i]-'A']);	
		}
	}*/
	
	printf("%.2lf", peek(&s));
	return 0;
}
