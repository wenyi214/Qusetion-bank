#include<stdio.h>
#include<stdbool.h>
//计数器，从1开始，判断是否是丑数，是的话计数器加1，直到等于n
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