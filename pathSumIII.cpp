//利用数的前序遍历
//双递归，外层递归，控制从哪个跟家电开始计算，里层递归，求路径和等于targetsum的个数。
//由于有负数，不能直接返回，都走到根节点才返回。
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
	int count = 0;
	void backtracing(TreeNode* root, int targetSum, int sum){
		if (root == nullptr){
			return;
		}
		//计算结点和
		sum += root->val;
		//有负数,不能直接返回
		// if(sum>targetSum){           
		//     return;   
		// }
		if (sum == targetSum){
			count++;
		}
		backtracing(root->left, targetSum, sum);
		backtracing(root->right, targetSum, sum);

	}
public:
	int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr){
			return 0;
		}
		//计算路径和
		backtracing(root, targetSum, 0);
		//外层递归
		pathSum(root->left, targetSum);
		pathSum(root->right, targetSum);
		return count;
	}
};