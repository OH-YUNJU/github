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
	
	printf("�л���: ");
	scanf("%d", &n);

	printf("���� �Է�:");
	
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
	
	printf("���(�ְ���, ������ ����): %.1f\n", avg);
	
	int select;
	int k[50];
		for (i = 0; i < n; i++) {
  		k[i] = m[i];
 }
	
	while(1) {
	
	printf("\n1. ��������\n");
	printf("2. ��������\n");
	printf("3. �Է¼�\n");
	printf("0. ����\n");
	
	printf("����: ");
	scanf("%d", &select);
	
	switch(select) {
		case 1:
			printf("��������: ");
			asc_sort(m, n);
			for(i = 0; i < n; i++)
			printf("%d ", m[i]);
			break;
		case 2:
			printf("��������: ");
			desc_sort(m, n);
			for(i = 0; i < n; i++)
			printf("%d ", m[i]);
			break; 
		case 3:
			printf("�Է¼�: ");
			for(i = 0; i < n; i++)
			printf("%d ", k[i]);
			break; 
	  
	}
		if(select == 0) {
			printf("�����մϴ�.\n");
			break;
		}
}
}


