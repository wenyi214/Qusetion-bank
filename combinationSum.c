#include<stdio.h>
#include<stdlib.h>
//leetcode 39 组合总和
int **result;
int *path;
int j = 0;

void backtracking(int *a, int len, int target, int startindex, int num, int *returnSize, int **returnColumnSizes){
	if (num>target){
		return;
	}
	if (num == target){
		result[(*returnSize)] = (int *)malloc(sizeof(int)*(j + 1));
		(*returnColumnSizes)[(*returnSize)] = j;
		for (int i = 0; i <= j; i++){
			result[(*returnSize)][i] = path[i];
		}
		(*returnSize)++;
	}
	//剪枝
	//排好序，如果num+candidates[i]>target就没必要进循环了，因为排好序，后面的也没必要进循环了
	for (int i = startindex; i<len&&num + a[i] <= target; i++){


		num += a[i];
		path[j++] = a[i];
		backtracking(a, len, target, i, num, returnSize, returnColumnSizes);
		j--;
		num -= a[i];
	}
}
int cmp(const void *_px,const void *_py){
	int *px = (int *)_px;
	int *py = (int *)_py;
	if (*px>*py){
		return 1;
	}
	if (*px<*py){
		return -1;
	}
	return 0;
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	result = (int **)malloc(sizeof(int *)* 10000);
	path = (int *)malloc(sizeof(int)* 10000);
	*returnColumnSizes = (int *)malloc(sizeof(int)* 1000);
	*returnSize = 0;
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	backtracking(candidates, candidatesSize, target, 0, 0, returnSize, returnColumnSizes);

	free(path);
	return result;
}
int main(){
	return 0;
}