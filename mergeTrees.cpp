//递归实现
//都为空直接返回空
//一棵树为空，直接返回不为空的树
//都不为空，构建结点返回
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
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr){
			return nullptr;
		}
		int x = 0;
		//一个为空，直接返回另外一个
		if (root1 == nullptr){
			return root2;
		}
		else if (root2 == nullptr){
			return root1;
		}
		//都不为空
		else{
			x = root2->val + root1->val;
		}
		//构建一个结点返回
		TreeNode* head = new TreeNode(x);
		head->left = mergeTrees(root1->left, root2->left);
		head->right = mergeTrees(root1->right, root2->right);
		return head;

	}
};