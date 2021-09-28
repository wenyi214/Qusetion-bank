//�������·���͵����ֵ���н���ұ�·�������ֵ
//��һ��ȫ�ֱ���������ÿһ�����·�������ֵ
//ע����һ���ǣ������߽��·�����ֵС��0��ֱ�����������ֵ��Ϊ0
//����ұ߽��·�����ֵС��0��ֱ�����������ֵ��Ϊ0���ӵ�ǰ��㿪ʼ���㣬����ֻ���С�͵�ֵ��
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
		//��������·�����ֵ��
		//���������·�����ֵ�Ǹ�����ֱ������
		int leftmax = max(GetMaxSum(root->left), 0);
		int rightmax = max(GetMaxSum(root->right), 0);
		//������¼ÿһ�����·���͵����ֵ
		maxsum = max(maxsum, leftmax + rightmax + root->val);
		//��ǰ����·�����ֵ�����·���ͣ��ұ�·�������ֵ���ϵ�ǰ���ֵ
		return max(leftmax + root->val, rightmax + root->val);

	}
public:
	int maxPathSum(TreeNode* root) {

		GetMaxSum(root);

		return maxsum;
	}
};