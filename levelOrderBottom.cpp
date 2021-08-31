//ֱ����res��ת
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
		//���м�¼���
		queue<TreeNode*> q;
		q.push(cur);
		while (!q.empty()){
			int size = q.size();
			tmp.resize(size);
			//��ѭ������ÿһ��������ŵ�����tmp��
			for (size_t i = 0; i<size; i++){
				//������front��ջ��top
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
		//��ת��res��Ԫ�أ�res��Ԫ����һ��һά����
		reverse(res.begin(), res.end());
		return res;

	}
};