#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *a = (int *)malloc(sizeof(int)* 2);
	for (int i = 0; i<numsSize - 1; i++){
		a[0] = nums[i];
		int x = target - nums[i];
		int left = i;
		int right = numsSize - 1;
		while (left <= right){
			int mid = left + (right - left) / 2;
			if (nums[mid]<x){
				left = mid + 1;
			}
			else if (nums[mid]>x){
				right = mid - 1;
			}
			else{
				a[1] = nums[mid];
				break;
			}

		}
		if (left <= right){
			break;
		}
	}
	return a;

}
int main(){
	return 0;
}
