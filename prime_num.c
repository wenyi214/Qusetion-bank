#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

int Prime(int i){
	for (int j = 2; j <= sqrt(i); j++){//�ж�������ʱ��Χ��С,�㵽i�Ŀ�ƽ��
		if (i%j == 0){
			return 0;
		}
	}
	return 1;
}


int main(){
	int a = 0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++){
		if (Prime(i)){
			printf("%d ", i);
		}

	}
	printf("\n");
	system("pause");
	return 0;
}