#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//���������ȷ����ջҪ�����ٿռ�
int Getleaf(struct TreeNode *root){
	if (root == NULL){
		return 0;
	}
	return Getleaf(root->left) + Getleaf(root->right) + 1;
}

struct TreeNode* convertBiNode(struct TreeNode* root){
	if (root == NULL){
		return NULL;
	}
	struct TreeNode *cur = root;
	//����ͷ�ڵ�
	struct TreeNode *dummy = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	dummy->left = NULL;
	dummy->right = NULL;
	//����һ�������Զָ�����һ����㣬�����ӽ��
	struct TreeNode *rear = dummy;
	//����ջ
	int n = Getleaf(root);
	struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*n);
	int top = -1;
	//�������
	while (cur || top != -1){
		while (cur){
			stack[++top] = cur;
			cur = cur->left;
		}
		cur = stack[top--];
		//�������ÿ�
		cur->left = NULL;
		//���ӽ��
		rear->right = cur;
		rear = rear->right;

		cur = cur->right;
	}

	struct TreeNode *ass = dummy->right;
	free(dummy);
	free(stack);
	return ass;

}

int main(){
	return 0;
}