//��Ŀ��˼�ǣ�
//��������"()"����������������"()"������������Ҳ�����������
//������Ϊ�գ���������Ϊ�գ���ʡ���������š�
//����˼·��
//�õݹ�
//��string���ո��ڵ㡣stringҪ��Ϊ��Ա������
//��ڵ㲻Ϊ�գ��ȼ�һ��'('���ݹ������������ؼӷ�����')'
//�ҽڵ���ͬ��
//������Ϊ�գ���������Ϊ�ռ�����"()"��
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
		//����ת�ַ�����atoi���ַ���ת������
		_res += to_string(root->val);
		if (root->left){
			_res += '(';
			tree2str(root->left);
			_res += ')';
		}
		//������Ϊ�գ���������Ϊ��
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