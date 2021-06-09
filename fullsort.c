#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int a[32] = { 0 };
int b[32] = { 0 };

void Fullsort(int n, int count){
	if (count == n){
		for (int i = 0; i < n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++){
		if (b[i] == 0){
			a[count] = i;//将数据保存在数组里
			b[i] = 1;//使改位数在递归时失效
			Fullsort(n, count + 1);
			b[i] = 0;//使改位数递归完后起效
		}
	}

}

int main(){
	Fullsort(3, 0);

	system("pause");
	return 0;
}