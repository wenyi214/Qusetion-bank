#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//求结点个数，确认有栈要开多少空间
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
	//设置头节点
	struct TreeNode *dummy = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	dummy->left = NULL;
	dummy->right = NULL;
	//设置一个结点永远指向最后一个结点，好连接结点
	struct TreeNode *rear = dummy;
	//开辟栈
	int n = Getleaf(root);
	struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *)*n);
	int top = -1;
	//中序遍历
	while (cur || top != -1){
		while (cur){
			stack[++top] = cur;
			cur = cur->left;
		}
		cur = stack[top--];
		//左子树置空
		cur->left = NULL;
		//连接结点
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