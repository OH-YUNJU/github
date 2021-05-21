#include <stdio.h>
#include <stdlib.h>

char arr[1001] = { 0 };
int ballnum[1001];
int result = 1;
int num;

void ball(int value) {
	int i = 0;
	
	if (value > 0)
		while (i < value) {
			result++;
			
			if (result == num + 1) {
				result = 0;
				continue;
			}
			else if (arr[result])
				continue;
			i++;
		}
		
	else
		while (i > value) {
			result--;
			if (result == 0) {
				result = num + 1;
				continue;
			}
			if (arr[result])
				continue;
			i--;
		}

	arr[result] = 1;
	
}

int main() {
	
	scanf("%d", &num);
	
	arr[1] = 1;
	
	for (int i = 0; i < num; i++)
		scanf("%d", &ballnum[i]);
		
	for (int i = 0; i < num; i++) {
		printf("%d ", result);
		
		/*if (i == num - 1)
			break;*/
			
		ball(ballnum[result - 1]);	
	}
	
	return 0;
}
