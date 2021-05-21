#include <stdio.h>

void asc_sort(int m[], int n);
void desc_sort(int m[], int n);
void put(int m[], int n);

void asc_sort(int m[], int n) {
	int i, j, tmp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (m[i] > m[j]) {
                tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    }
}

void desc_sort(int m[], int n) {
	int i, j, tmp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (m[i] < m[j]) {
                tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    }

}


int main(void) {
	
	int n, i;
	int m[50];
	int max = 0, min = 10000;
	int sum = 0;
	double avg = 0;
	
	printf("학생수: ");
	scanf("%d", &n);

	printf("점수 입력:");
	
	for (i = 0; i < n; i++) {
		scanf("%d", &m[i]); 
		sum += m[i];
						
			if (m[i] > max)   
				max = m[i];
			if (m[i] < min)  
				min = m[i];
			
		}
		sum = sum - max - min;
		avg = sum / (n-2);
	
	printf("평균(최고점, 최저점 제외): %.1f\n", avg);
	
	int select;
	int k[50];
		for (i = 0; i < n; i++) {
  		k[i] = m[i];
 }
	
	while(1) {
	
	printf("\n1. 오름차순\n");
	printf("2. 내림차순\n");
	printf("3. 입력순\n");
	printf("0. 종료\n");
	
	printf("선택: ");
	scanf("%d", &select);
	
	switch(select) {
		case 1:
			printf("오름차순: ");
			asc_sort(m, n);
			for(i = 0; i < n; i++)
			printf("%d ", m[i]);
			break;
		case 2:
			printf("내림차순: ");
			desc_sort(m, n);
			for(i = 0; i < n; i++)
			printf("%d ", m[i]);
			break; 
		case 3:
			printf("입력순: ");
			for(i = 0; i < n; i++)
			printf("%d ", k[i]);
			break; 
	  
	}
		if(select == 0) {
			printf("종료합니다.\n");
			break;
		}
}
}


