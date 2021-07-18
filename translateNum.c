#include<stdio.h>
#include<stdlib.h>

int translateNum(int num){
	if (num == 0){
		return 1;
	}
	//记录元素个数
	int numsize = 0;
	int tmp = num;
	while (tmp){
		tmp /= 10;
		numsize++;
	}
	//放到数组中
	int *n = (int *)malloc(sizeof(int)*numsize);
	for (int i = numsize - 1; i >= 0; i--){
		n[i] = num % 10;
		num /= 10;
	}
	//dp数组为记翻译个数的数组
	int *dp = (int *)calloc(sizeof(int), numsize + 1);
	//初始化前两个
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 1; i<numsize; i++){
		//如果与前面一个数组合是否可以翻译
		int x = (n[i - 1] * 10) + n[i];
		if ((x<0 || x>25) || n[i - 1] == 0){
			dp[i + 1] = dp[i];
		}
		else{
			dp[i + 1] = dp[i] + dp[i - 1];
		}
	}
	int ass = dp[numsize];
	free(dp);
	free(n);

	return dp[numsize];

}

int main(){
	return 0;
}