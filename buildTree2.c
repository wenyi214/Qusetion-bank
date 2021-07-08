#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * CreatTree(int *in, int left1, int right1, int *post, int left2, int right2){
	if (left1>right1 || left2>right2){
		return NULL;
	}
	int k = left1;
	while (in[k] != post[right2]){
		k++;
	}

	struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tree->val = post[right2];
	//这里K不是个数，个数要减left1
	tree->left = CreatTree(in, left1, k - 1, post, left2, left2 + k - 1 - left1);
	tree->right = CreatTree(in, k + 1, right1, post, left2 + k - left1, right2 - 1);
	return tree;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	if (inorderSize == 0 || postorderSize == 0){
		return NULL;
	}
	return CreatTree(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);


}

int main(){
	return 0;
}