#include<stdio.h>
//Լɪ��
int lastRemaining(int n, int m){
	//ֻ��һ����ʱ����Ϊ0
	int flag = 0;
	//�������˿�ʼ
	for (int i = 2; i <= n; i++){
		//ǰһ�δ������ƣ���һ�δ���˵�����
		flag = (flag + m) % i;
	}
	return flag;
}
int main(){
	return 0;
}