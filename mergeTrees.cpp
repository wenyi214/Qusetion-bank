//�ݹ�ʵ��
//��Ϊ��ֱ�ӷ��ؿ�
//һ����Ϊ�գ�ֱ�ӷ��ز�Ϊ�յ���
//����Ϊ�գ�������㷵��
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
		//һ��Ϊ�գ�ֱ�ӷ�������һ��
		if (root1 == nullptr){
			return root2;
		}
		else if (root2 == nullptr){
			return root1;
		}
		//����Ϊ��
		else{
			x = root2->val + root1->val;
		}
		//����һ����㷵��
		TreeNode* head = new TreeNode(x);
		head->left = mergeTrees(root1->left, root2->left);
		head->right = mergeTrees(root1->right, root2->right);
		return head;

	}
};