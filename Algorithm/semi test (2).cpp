#include<stdio.h>
#include<string.h>  

//��,,,,,,, 85���ζ�� �ߴ� �� ������ּ���,,,,,,,,, 
 
int main(void) {
    char str[1024];
    char str2[1024];
    char *ptr;
    char str3[1024];
    int len = 1024;
 	int word, num, sum = 0;
 	int i, k;
 	
		printf("���� �Է�: ");
		 
		while(1) {
			gets(str);
			
			if(strcmp(str, "\0") == 0) {
				break;
			}
			
			if(strlen(str) < len) {
				len = strlen(str);
				strcpy(str2, str);			
			}
			
			for(i = 0; str[i]!= 0; i++) {
        		if (str[i]==' ')
            		word++;
        	}
            	ptr = strtok(str, " ");
            	strcpy(str3, ptr);
            	while (ptr = strtok(str, " ")) { 
					for (k = 0; k < str3[k]; k++) { 
  						if (strcmp(ptr, str3) == 0) { 
							word--; 
								break; 
						} 
					}
            	}
			
		    for(i = 0; str[i]!= NULL; i++) {		
    			if (str[i] >= '0' && str[i] <= '9') {
    				num = num + str[i] - '0';
				} 
			else {
				if (num > 0) {
					sum = sum + num;
					num = 0;
				}
			}
			}

}	

	printf("���� ª�� ����: %s\n", str2);

	printf("���ڹ��ڵ��� ����: %d\n", sum);
		
	printf("�� �ܾ��: %d\n", word+1);
	
	printf("���� �ܾ�: ");
	
/*	char *ptr = strtok(str, " ");
		while (ptr != NULL) {	
        printf("%s ", ptr);      
        ptr = strtok(NULL, " ");
    }*/

	return 0;
}
