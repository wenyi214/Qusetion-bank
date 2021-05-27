#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int main(){
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	while (a*b!=0){ //判断a或者b==0的方法
		if (a > b){ //要判断大小
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
