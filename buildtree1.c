//ǰ�������õ�������
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *GetTree(int *pre, int left1, int right1, int *in, int left2, int right2){
	if (left1>right1 || left2>right2){
		return NULL;
	}

	//�����k����left2�����ڵ�Ĳ�ֵ��������������и��ڵ��λ��
	//������������Ҹ��ڵ�
	int k = -1;
	while (in[++k] != pre[left1]);

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = pre[left1];

	//�����������ǰ����������������
	root->left = GetTree(pre, left1 + 1, left1 + k, in, left2, k - 1);

	//�����������ǰ����������������
	//pre����߽�Ҫ��left2����ΪK������������и��ڵ㵽��߽�Ĳ�ֵ����������λ��
	root->right = GetTree(pre, left1 + k + 1 - left2, right1, in, k + 1, right2);

	return root;

}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

	return GetTree(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);

}

int main(){
	return 0;
}