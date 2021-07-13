#include<stdio.h>
#include<stdlib.h>
//target，最少两数相加等于targrt，所以遍历的数最大到target/2+1。
//双指针法，一个指向左边，一个指向左边的下一个，如果小于target，，sum += right，right++。等于将数放入数组。大于，sum -= left，left++。，直到right大于等于target / 2 + 1
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
	int n = target / 2 + 1;
	//本来是想开辟一个数组，将数放里
	//不许要开辟，直接用left和right值就行
	// int *a=(int *)malloc(sizeof(int)*n);
	// for(int i=1;i<=n;i++){
	//     a[i-1]=i;
	// }

	int **result = (int **)malloc(sizeof(int *)*n);
	*returnColumnSizes = (int *)malloc(sizeof(int)*n);
	*returnSize = 0;
	//一个指向左边
	int left = 1;
	//左边下一个
	int right = left + 1;
	//和
	int sum = left;

	int k = 0;

	while (right <= n){
		//和加右边的
		sum += right;
		//大于sum放出前面的值
		while (sum>target){
			sum -= left;
			left++;
		}
		//等于将值纳入数组，再将值拿出，计算后面的
		if (sum == target){
			result[(*returnSize)] = (int *)malloc(sizeof(int)*(right - left + 1));
			(*returnColumnSizes)[(*returnSize)] = right - left + 1;
			for (int i = left; i <= right; i++){
				//k记录数组的列
				result[(*returnSize)][k++] = i;
			}
			(*returnSize)++;
			//记录完后，要再从0开始
			k = 0;
			sum -= left;
			left++;

		}

		right++;
	}
	// free(a);
	// a=NULL;
	return result;

}
int main(){
	return 0;
}