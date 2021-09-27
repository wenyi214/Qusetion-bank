//��������ǰ�����
//˫�ݹ飬���ݹ飬���ƴ��ĸ����ҵ翪ʼ���㣬���ݹ飬��·���͵���targetsum�ĸ�����
//�����и���������ֱ�ӷ��أ����ߵ����ڵ�ŷ��ء�
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
		//�������
		sum += root->val;
		//�и���,����ֱ�ӷ���
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
		//����·����
		backtracing(root, targetSum, 0);
		//���ݹ�
		pathSum(root->left, targetSum);
		pathSum(root->right, targetSum);
		return count;
	}
};