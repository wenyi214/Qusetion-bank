//���Ƿ���һ�����ɣ�
//���ӵ��ڸ��׼����������ĺ͡�
//��������������������������򼯺ϣ�������������ڽ��򼯺ϡ�
//���ǿ��Է�������������ֵ�͵��ڰ�����ǰ���ֵǰ��͵�ֵ��
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
	//�ۼӺ�ֵ
	int sum = 0;
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr){
			return nullptr;
		}
		//���������������������ʼ
		convertBST(root->right);
		//sumΪ������ǰ���ǰ����ֵ
		sum += root->val;
		root->val = sum;
		convertBST(root->left);
		return root;
	}
};