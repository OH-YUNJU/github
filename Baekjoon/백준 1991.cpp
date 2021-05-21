#include <stdio.h>

char arr[26][3]; 
int num;  

void preorder(char a) { 
 	for (int i = 0; i < num; i++) { 
 		if (arr[i][0] == a) { 
 			printf("%c", a); 
 			if (arr[i][1] != '.')
				preorder(arr[i][1]); 
 			if (arr[i][2] != '.') 
				preorder(arr[i][2]); 
 		} 
 	} 
} 
 
void inorder(char a) { 
 	for (int i = 0; i < num; i++) { 
 		if (arr[i][0] == a) { 
 			if (arr[i][1] != '.') 
				inorder(arr[i][1]); 
 				printf("%c", a); 
 				
 			if (arr[i][2] != '.') 
				inorder(arr[i][2]); 
 		} 
 	} 
} 
 
void postorder(char a) { 
 		for (int i = 0; i < num; i++) { 
 			if (arr[i][0] == a) { 
 				if (arr[i][1] != '.') 
					postorder(arr[i][1]); 
 				if (arr[i][2] != '.') 
					postorder(arr[i][2]); 
 				printf("%c", a); 
 			} 
 		} 
} 

 
int main() { 
 	scanf("%d", &num); 
 	
 	for (int i = 0; i < num; i++) 
	 	scanf(" %c %c %c", &arr[i][0], &arr[i][1], &arr[i][2]);
		  	 
 	preorder('A'); 
 	printf("\n");  
 	inorder('A'); 
 	printf("\n"); 
 	postorder('A'); 
 	printf("\n"); 
 	
 	return 0; 
 } 
