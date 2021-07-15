#include<stdio.h>
#include<stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *result = (int *)malloc(sizeof(int)* 2);
	result[0] = -1;
	result[1] = -1;

	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	while (left <= right){
		mid = left + (right - left) / 2;
		if (nums[mid]>target){
			right = mid - 1;
		}
		if (nums[mid]<target){
			left = mid + 1;
		}
		if (nums[mid] == target){
			break;
		}
	}
	if (left <= right){
		int start = mid;
		int end = mid;
		while (start >= 0 && nums[start] == target){
			start--;
		}
		while (end<numsSize&&nums[end] == target){
			end++;
		}
		result[0] = start + 1;
		result[1] = end - 1;
	}
	*returnSize = 2;
	return result;
}

int main(){
	return 0;
}