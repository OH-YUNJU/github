#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char i;
	int arr[255];
	int i = 0;
	int n;
	
	scanf("%s", arr);
	scanf("%d", &n);
	
	for(i = 'A'; i <= 'Z'; i++) {
		arr[i - 'A'] += 1;
	}
	
	* (n+1) + 
}
