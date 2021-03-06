//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL || root == p || root == q){
		return root;
	}
	struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
	struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left != NULL&&right != NULL){
		return root;
	}
	if (left == NULL&&right != NULL){
		return right;
	}
	return left;

}