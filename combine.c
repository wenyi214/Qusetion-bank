//c语言 回溯解决组合问题
#include<stdio.h>
#include<stdlib.h>

int **result;//保存结果
int *path;//存储每一个路径值
int j = 0;
void backtracking(int n, int k, int startindex, int *returnSize){
	//终止条件，当path中个数等于要求个数k时
	if (j == k){
		result[(*returnSize)] = (int *)malloc(sizeof(int)*k);
		for (int i = 0; i<k; i++){
			result[(*returnSize)][i] = path[i];
		}
		(*returnSize)++;
		return;
	}

	for (int i = startindex; i <= n; i++){
		//将一个数放入
		path[j++] = i;
		//递归，
		backtracking(n, k, i + 1, returnSize);
		//回溯，将最后一个数弹出
		j--;
	}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
	//申请行10000的二维数组
	result = (int **)malloc(sizeof(int *)* 10000);
	//path个数为K个
	path = (int *)malloc(sizeof(int)*k);

	*returnSize = 0;
	//回溯函数，递归函数
	backtracking(n, k, 1, returnSize);
	//leetcode储存列的数组申请空间
	*returnColumnSizes = (int *)malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i<(*returnSize); i++){
		(*returnColumnSizes)[i] = k;
	}
	return result;
}

int main(){
	return 0;
}