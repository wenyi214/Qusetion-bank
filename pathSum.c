#include<stdio.h>
#include<stdlib.h>
//求树的路径和，leetcode面试题04.12
//利用栈来解，DFS
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
	//将做子树存入栈中，直到遇到空。
	while (top != -1 || cur){
		while (cur){
			k += cur->val;
			//如果等于要求值，加1
			if (k == sum){
				(*count)++;
			}
			stack[++top] = cur;
			cur = cur->left;
		}
		//出栈一个
		cur = stack[top--];
		//如果右边为空，或者右边已经走过
		if (cur->right == NULL || cur->right == tmp){
			k -= cur->val;
			//记录遍历过的结点
			tmp = cur;
			//直接将结点置空，直接出栈一节点
			cur = NULL;
		}
		//如果右边不为空，并且没走过
		else{
			//将出栈结点入栈，往右边走
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