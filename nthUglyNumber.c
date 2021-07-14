#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int Min(int a, int b, int c){
	int min = a;
	if (min>b){
		min = b;
	}
	if (min>c){
		min = c;
	}
	return min;
}

int nthUglyNumber(int n){
	//放丑数数组
	int *ugly = (int *)malloc(sizeof(int)*(n + 1));
	//清0
	memset(ugly, 0, sizeof(int)*(n + 1));
	//第一个丑数
	ugly[1] = 1;
	//三个指针指向第一个位置
	int p1 = 1, p2 = 1, p3 = 1;
	//从第二个位置开始。第一个位置放了
	for (int i = 2; i <= n; i++){
		//乘以权值，得到三个丑数
		int nums1 = ugly[p1] * 2, nums2 = ugly[p2] * 3, nums3 = ugly[p3] * 5;
		//选出最小的丑数放后面
		ugly[i] = Min(nums1, nums2, nums3);
		//最小数指针加1，避免重复数
		if (ugly[i] == nums1){
			p1++;
		}
		if (ugly[i] == nums2){
			p2++;
		}
		if (ugly[i] == nums3){
			p3++;
		}
	}
	return ugly[n];

}
int main(){
	return 0;
}