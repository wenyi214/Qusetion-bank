//�ж�һ�����Ƿ���ƽ�������
//�жϽڵ����Ҹ߶Ⱦ���ֵ�Ƿ񳬹�2
#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int GetHigh(struct TreeNode *root){
	if (root == NULL){
		return 0;
	}
	int lh = GetHigh(root->left);
	int rh = GetHigh(root->right);
	int h = lh>rh ? lh : rh;
	return h + 1;
}


bool isBalanced(struct TreeNode* root){
	if (root == NULL){
		return true;
	}
	if (GetHigh(root->left) - GetHigh(root->right) >= 2 || \
		GetHigh(root->left) - GetHigh(root->right) <= -2){
		return false;
	}

	return isBalanced(root->left) && isBalanced(root->right);

}

int main(){
	return 0;
}