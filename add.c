#include<stdio.h>

int add(int a, int b){
	//将b看作进位
	while (b){
		//没有进位的二进制
		int tmp = a^b;
		//进位
		b = (unsigned int)(a&b) << 1;
		a = tmp;
	}
	return a;
}
int main(){
	return 0;
}