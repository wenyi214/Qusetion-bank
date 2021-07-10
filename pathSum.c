#include<stdio.h>
#include<stdlib.h>
//������·���ͣ�leetcode������04.12
//����ջ���⣬DFS
struct TreeNode{
	struct TreeNode *left;
	struct TreeNode *right;
	int val;
};

void Sum(struct TreeNode *root, int sum, struct TreeNode **stack, int *count){
	if (root == NULL){
		return;
	}
	int k = 0;
	int top = -1;
	struct TreeNode *cur = root;
	struct TreeNode *tmp = NULL;
	//������������ջ�У�ֱ�������ա�
	while (top != -1 || cur){
		while (cur){
			k += cur->val;
			//�������Ҫ��ֵ����1
			if (k == sum){
				(*count)++;
			}
			stack[++top] = cur;
			cur = cur->left;
		}
		//��ջһ��
		cur = stack[top--];
		//����ұ�Ϊ�գ������ұ��Ѿ��߹�
		if (cur->right == NULL || cur->right == tmp){
			k -= cur->val;
			//��¼�������Ľ��
			tmp = cur;
			//ֱ�ӽ�����ÿգ�ֱ�ӳ�ջһ�ڵ�
			cur = NULL;
		}
		//����ұ߲�Ϊ�գ�����û�߹�
		else{
			//����ջ�����ջ�����ұ���
			stack[++top] = cur;
			cur = cur->right;
		}

	}
	Sum(root->left, sum, stack, count);
	Sum(root->right, sum, stack, count);

}

int pathSum(struct TreeNode* root, int sum){

	struct TreeNode **a = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
	int count = 0;
	Sum(root, sum, a, &count);
	free(a);
	a = NULL;
	return count;
}

int main(){
	return 0;
}