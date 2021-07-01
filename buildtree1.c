//前序和中序得到二叉树
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

	//这里的k不是left2到根节点的差值，而是中序遍历中根节点的位置
	//在中序遍历中找根节点
	int k = -1;
	while (in[++k] != pre[left1]);

	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = pre[left1];

	//算好左子树在前序，中序遍历里的区间
	root->left = GetTree(pre, left1 + 1, left1 + k, in, left2, k - 1);

	//算好右子树在前序，中序遍历里的区间
	//pre的左边界要减left2，因为K不是中序遍历中根节点到左边界的差值，而是它的位置
	root->right = GetTree(pre, left1 + k + 1 - left2, right1, in, k + 1, right2);

	return root;

}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

	return GetTree(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);

}

int main(){
	return 0;
}