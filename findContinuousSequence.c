#include<stdio.h>
#include<stdlib.h>
//target������������ӵ���targrt�����Ա����������target/2+1��
//˫ָ�뷨��һ��ָ����ߣ�һ��ָ����ߵ���һ�������С��target����sum += right��right++�����ڽ����������顣���ڣ�sum -= left��left++����ֱ��right���ڵ���target / 2 + 1
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
	int n = target / 2 + 1;
	//�������뿪��һ�����飬��������
	//����Ҫ���٣�ֱ����left��rightֵ����
	// int *a=(int *)malloc(sizeof(int)*n);
	// for(int i=1;i<=n;i++){
	//     a[i-1]=i;
	// }

	int **result = (int **)malloc(sizeof(int *)*n);
	*returnColumnSizes = (int *)malloc(sizeof(int)*n);
	*returnSize = 0;
	//һ��ָ�����
	int left = 1;
	//�����һ��
	int right = left + 1;
	//��
	int sum = left;

	int k = 0;

	while (right <= n){
		//�ͼ��ұߵ�
		sum += right;
		//����sum�ų�ǰ���ֵ
		while (sum>target){
			sum -= left;
			left++;
		}
		//���ڽ�ֵ�������飬�ٽ�ֵ�ó�����������
		if (sum == target){
			result[(*returnSize)] = (int *)malloc(sizeof(int)*(right - left + 1));
			(*returnColumnSizes)[(*returnSize)] = right - left + 1;
			for (int i = left; i <= right; i++){
				//k��¼�������
				result[(*returnSize)][k++] = i;
			}
			(*returnSize)++;
			//��¼���Ҫ�ٴ�0��ʼ
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