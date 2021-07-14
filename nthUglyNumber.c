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
	//�ų�������
	int *ugly = (int *)malloc(sizeof(int)*(n + 1));
	//��0
	memset(ugly, 0, sizeof(int)*(n + 1));
	//��һ������
	ugly[1] = 1;
	//����ָ��ָ���һ��λ��
	int p1 = 1, p2 = 1, p3 = 1;
	//�ӵڶ���λ�ÿ�ʼ����һ��λ�÷���
	for (int i = 2; i <= n; i++){
		//����Ȩֵ���õ���������
		int nums1 = ugly[p1] * 2, nums2 = ugly[p2] * 3, nums3 = ugly[p3] * 5;
		//ѡ����С�ĳ����ź���
		ugly[i] = Min(nums1, nums2, nums3);
		//��С��ָ���1�������ظ���
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