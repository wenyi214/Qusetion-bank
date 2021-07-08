#include<stdio.h>
#include<stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int cmp(const void *_px, const void *_py){
	int *px = (int *)_px;
	int *py = (int *)_py;
	if (*px>*py){
		return 1;
	}
	else if (*px<*py){
		return -1;
	}
	return 0;
}

struct TreeNode *BuildTree(int *pre, int left1, int right1, int *in, int left2, int right2){
	if (left1>right1 || left2>right2){
		return NULL;
	}
	int i = left2;
	while (in[i] != pre[left1]){
		i++;
	}

	struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tree->val = pre[left1];

	tree->left = BuildTree(pre, left1 + 1, left1 + i, in, left2, i - 1);
	tree->right = BuildTree(pre, left1 + i + 1 - left2, right1, in, i + 1, right2);

	return tree;

}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
	if (preorderSize == 0){
		return NULL;
	}
	int *inorder = (int *)malloc(sizeof(int)*preorderSize);
	for (int i = 0; i<preorderSize; i++){
		inorder[i] = preorder[i];
	}
	//二叉搜索树，排序后获得中序遍历
	qsort(inorder, preorderSize, sizeof(int), cmp);

	return BuildTree(preorder, 0, preorderSize - 1, inorder, 0, preorderSize - 1);

}

int main(){
	return 0;
}