#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct StackType {
    char arr[100]; //int�� ������ 100��
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1; //�迭�� index 0���� ����
}

//empty : return 1
//!empty : return 0
int is_empty(StackType *s)
{
    if(s->top == -1)
        return 1;
    return 0;
}

//full : return 1
//!full : return 0
int is_full(StackType *s)
{
    if(s->top == SIZE - 1)
        return 1;
    return 0;
}

void push(StackType *s, char value)
{
    if(is_full(s))
    {
        printf("Stack is full");
        //exit(1);
    }
    s->arr[++(s->top)] = value;
}

char pop(StackType *s)
{
    if(is_empty(s))
    {
        printf("Stack is empty");
        //exit(1);
    }
    return s->arr[(s->top)--];
}

char peek(StackType *s)
{
    if(is_empty(s))
    {
        printf("Stack is empty");
        //exit(1);
    }
    return s->arr[(s->top)];
}

int cal(StackType *s) {
	int num1, j = 1;
	int k = 0;
	int i, num2;
	//StackType s;
	//init(&s);
	char str[100001];
	
    scanf("%d", &num1);
	
	while(k < num1*2) {
		scanf("%d", &num2);
	
		while(j <= num2) {
			push(s, j++);
			str[k++] = '+';
		}
		
		if (num2 != peek(s)) {
			printf("NO");		
		}

		str[k++] = '-';
		pop(s);
	}
	
	for(i = 0; i < k; i++) {
		printf("%c\n", str[i]);
	}
}

int main(void) {
	StackType s;
	init(&s);
	
	cal(&s);

    return 0;
}

