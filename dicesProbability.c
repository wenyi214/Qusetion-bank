#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double* dicesProbability(int n, int* returnSize){
	//n个骰子的所有情况
	*returnSize = 5 * n + 1;
	//求出只有一个骰子时数组
	double *res = (double *)malloc(sizeof(double)* 6);
	for (int i = 0; i<6; i++){
		res[i] = 1.0 / 6;
	}
	//外层循环，骰子个数
	for (int i = 2; i <= n; i++){
		//创建一个i个骰子时的数组，并初始化为0
		double *ass = (double *)malloc(sizeof(double)*(5 * i + 1));
		memset(ass, 0, sizeof(double)*(5 * i + 1));
		//求每一个数的概率
		//f(n-1)数影响f(n)数
		for (int j = 0; j<5 * (i - 1) + 1; j++){//f(n-1)数的个数
			for (int k = j; k<j + 6; k++){//影响个数
				ass[k] += res[j] / 6;
			}
		}
		//交替
		free(res);
		res = ass;
	}
	return res;

}

int main(){
	return 0;
}

