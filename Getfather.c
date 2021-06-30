struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	
};
struct TreeNode *Getfather(struct TreeNode *root, struct TreeNode *node){
	if (root == NULL){
		return NULL;
	}
	if (root->left == node || root->right == node){
		return root;
	}
	struct TreeNode *sum = NULL;
	sum = Getfather(root->left, node);
	if (sum == NULL){
		sum = Getfather(root->right, node);
	}
	return sum;

}