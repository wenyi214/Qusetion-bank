#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double* dicesProbability(int n, int* returnSize){
	//n�����ӵ��������
	*returnSize = 5 * n + 1;
	//���ֻ��һ������ʱ����
	double *res = (double *)malloc(sizeof(double)* 6);
	for (int i = 0; i<6; i++){
		res[i] = 1.0 / 6;
	}
	//���ѭ�������Ӹ���
	for (int i = 2; i <= n; i++){
		//����һ��i������ʱ�����飬����ʼ��Ϊ0
		double *ass = (double *)malloc(sizeof(double)*(5 * i + 1));
		memset(ass, 0, sizeof(double)*(5 * i + 1));
		//��ÿһ�����ĸ���
		//f(n-1)��Ӱ��f(n)��
		for (int j = 0; j<5 * (i - 1) + 1; j++){//f(n-1)���ĸ���
			for (int k = j; k<j + 6; k++){//Ӱ�����
				ass[k] += res[j] / 6;
			}
		}
		//����
		free(res);
		res = ass;
	}
	return res;

}

int main(){
	return 0;
}

