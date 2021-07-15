#include<stdio.h>
#include<stdbool.h>
//����������1��ʼ���ж��Ƿ��ǳ������ǵĻ���������1��ֱ������n
bool isUgly(int n){
	if (n == 0){
		return false;
	}
	while (n % 2 == 0){
		n /= 2;
	}
	while (n != 0 && n % 3 == 0){
		n /= 3;
	}
	while (n != 0 && n % 5 == 0){
		n /= 5;
	}
	if (n == 1){
		return true;
	}
	return false;

}

int nthUglyNumber(int n){
	int count = 0;
	int i = 0;
	while (count != n){
		i++;
		if (isUgly(i)){
			count++;
		}

	}
	return i;
}
int main(){
	return 0;
}