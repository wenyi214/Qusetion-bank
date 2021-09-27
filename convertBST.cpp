//我们发现一个规律：
//左孩子等于父亲及其右子树的和。
//二叉搜索树，中序遍历等于升序集合，反中序遍历等于降序集合。
//我们可以反中序遍历，结点值就等于包括当前结点值前面和的值。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
private:
	//累加和值
	int sum = 0;
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		//反中序遍历，从右子树开始
		convertBST(root->right);
		//sum为包括当前结点前面结点值
		sum += root->val;
		root->val = sum;
		convertBST(root->left);
		return root;
	}
};