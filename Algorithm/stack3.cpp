#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Stack{
	int arr[SIZE];
	int top;
	 
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
int Check_Stack(char *in) {
	Stack s;
	char ch, open_ch;
	int len;
	len = strlen(in);
	init(&s);
	
for (int i = 0; i < len; i++) {
	ch = in[i];
	
	switch (ch) {
		case '(': case '{':
			push(&s, ch);
			break;
			
		case ')': case '}':
			if(is_empty(&s))
				return 0;
			
			open_ch = pop(&s);
			
			if (open_ch == '(' && ch != ')')
				return 0;
			if (open_ch == '{' && ch != '}')
				return 0;
			
			break;
		/*case '{': case 
			puseh(&s, ch);
			break;
		case '}':
			if(is_empty(&s))
				return 0;
			else {
				open_ch = pop(&s);
			}
			break*/
	}
}
	if (!is_empty(&s))
		return 0;
	return 1;
}

int main(int argc, const char * argv[]) {
   char str[51];
   int n;
	
	scanf("%d", &n);
        
   		for (int i = 0; i < n; i++) {
      		scanf("%s", str);
      
      		if (Check_Stack(str) == 1)
         		printf("YES\n");
      		else
         		printf("NO\n");
    		}
		
   return 0;
}
