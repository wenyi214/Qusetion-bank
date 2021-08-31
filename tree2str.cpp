//题目意思是：
//左子树用"()"括起来，右子树用"()"括起来。子树也是这种情况。
//左子树为空，右子树不为空，不省略整个括号。
//解题思路：
//用递归
//用string接收根节点。string要作为成员变量。
//左节点不为空，先加一个'('，递归左子树，返回加反括号')'
//右节点相同。
//左子树为空，右子树不为空加整个"()"。
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
	string _res;
	string tree2str(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		//整数转字符串，atoi是字符串转整数。
		_res += to_string(root->val);
		if (root->left){
			_res += '(';
			tree2str(root->left);
			_res += ')';
		}
		//左子树为空，右子树不为空
		else if (root->right){
			_res += "()";
		}

		if (root->right){

			_res += '(';
			tree2str(root->right);
			_res += ')';
		}

		return _res;

	}
};