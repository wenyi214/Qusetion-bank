#include<stdio.h>
//约瑟夫环
int lastRemaining(int n, int m){
	//只有一个人时坐标为0
	int flag = 0;
	//从两个人开始
	for (int i = 2; i <= n; i++){
		//前一次存活的人推，下一次存活人的坐标
		flag = (flag + m) % i;
	}
	return flag;
}
int main(){
	return 0;
}