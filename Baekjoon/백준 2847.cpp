#include <stdio.h>

int main() {
	int num;
	int score = 0;
	int arr[100];
	
	scanf("%d", &num);
	
	for(int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int j = num - 2; j > -1; j--) {
		if (arr[j] >= arr[j + 1]) {
			score = score + arr[j] - (arr[j + 1] - 1);
			arr[j] = arr[j + 1] - 1;
		}		
	}
	
	printf("%d", score);
	
	return 0;
	
} 
