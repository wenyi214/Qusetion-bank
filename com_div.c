#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int main(){
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	while (a*b!=0){ //�ж�a����b==0�ķ���
		if (a > b){ //Ҫ�жϴ�С
			a %= b;
		}
		else{
			b %= a;
		}
	}
	printf("%d\n", a + b);
	system("pause");
	return 0;
}
