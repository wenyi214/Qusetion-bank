#include<stdio.h>

int add(int a, int b){
	//��b������λ
	while (b){
		//û�н�λ�Ķ�����
		int tmp = a^b;
		//��λ
		b = (unsigned int)(a&b) << 1;
		a = tmp;
	}
	return a;
}
int main(){
	return 0;
}