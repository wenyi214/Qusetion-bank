//c���� ���ݽ���������
#include<stdio.h>
#include<stdlib.h>

int **result;//������
int *path;//�洢ÿһ��·��ֵ
int j = 0;
void backtracking(int n, int k, int startindex, int *returnSize){
	//��ֹ��������path�и�������Ҫ�����kʱ
	if (j == k){
		result[(*returnSize)] = (int *)malloc(sizeof(int)*k);
		for (int i = 0; i<k; i++){
			result[(*returnSize)][i] = path[i];
		}
		(*returnSize)++;
		return;
	}

	for (int i = startindex; i <= n; i++){
		//��һ��������
		path[j++] = i;
		//�ݹ飬
		backtracking(n, k, i + 1, returnSize);
		//���ݣ������һ��������
		j--;
	}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
	//������10000�Ķ�ά����
	result = (int **)malloc(sizeof(int *)* 10000);
	//path����ΪK��
	path = (int *)malloc(sizeof(int)*k);

	*returnSize = 0;
	//���ݺ������ݹ麯��
	backtracking(n, k, 1, returnSize);
	//leetcode�����е���������ռ�
	*returnColumnSizes = (int *)malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i<(*returnSize); i++){
		(*returnColumnSizes)[i] = k;
	}
	return result;
}

int main(){
	return 0;
}