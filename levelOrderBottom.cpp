//直接用res反转
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr){
			return res;
		}
		vector<int> tmp;
		TreeNode *cur = root;
		//队列记录结点
		queue<TreeNode*> q;
		q.push(cur);
		while (!q.empty()){
			int size = q.size();
			tmp.resize(size);
			//用循环，将每一层的数，放到数组tmp里
			for (size_t i = 0; i<size; i++){
				//队列是front，栈是top
				TreeNode *tail = q.front();
				q.pop();
				tmp[i] = tail->val;
				if (tail->left){
					q.push(tail->left);
				}
				if (tail->right){
					q.push(tail->right);
				}
			}
			res.push_back(tmp);
		}
		//反转，res的元素，res的元素是一个一维数组
		reverse(res.begin(), res.end());
		return res;

	}
};