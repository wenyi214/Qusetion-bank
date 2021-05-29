#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

int Prime(int i){
	for (int j = 2; j <= sqrt(i); j++){//判断是素数时范围缩小,算到i的开平方
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