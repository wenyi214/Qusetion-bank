//求结点左边路径和的最大值，有结点右边路径和最大值
//用一个全局变量来保存每一个结点路径的最大值
//注意有一点是：如果左边结点路径最大值小于0，直接舍弃，最大值设为0
//如果右边结点路径最大值小于0，直接舍弃，最大值设为0，从当前结点开始计算，负数只会减小和的值。
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
	int maxsum = INT_MIN;
	int GetMaxSum(TreeNode* root){
		if (root == nullptr){
			return 0;
		}
		//求左子树路径最大值，
		//如果左子树路径最大值是负数，直接舍弃
		int leftmax = max(GetMaxSum(root->left), 0);
		int rightmax = max(GetMaxSum(root->right), 0);
		//这里会记录每一个结点路径和的最大值
		maxsum = max(maxsum, leftmax + rightmax + root->val);
		//当前结点的路径最大值，左边路径和，右边路径和最大值加上当前结点值
		return max(leftmax + root->val, rightmax + root->val);

	}
public:
	int maxPathSum(TreeNode* root) {

		GetMaxSum(root);

		return maxsum;
	}
};