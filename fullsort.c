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
			a[count] = i;//�����ݱ�����������
			b[i] = 1;//ʹ��λ���ڵݹ�ʱʧЧ
			Fullsort(n, count + 1);
			b[i] = 0;//ʹ��λ���ݹ������Ч
		}
	}

}

int main(){
	Fullsort(3, 0);

	system("pause");
	return 0;
}