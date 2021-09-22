//��һ�����������������Ϊ�գ���ǰӦ��������״̬���������Ϊû�б����ǣ�Ҷ�ӽ��ͻ�������ͷ�������Ϊ����ͷ��Ҷ�ӽ����Ǳ����ǣ����ڵ�Ͳ�����Ϊ����ͷ�����Կս��Ϊ�Ѹ���״̬��
//��ʱ��4�����
//1.��������ӽڵ㶼�Ǳ����ǣ���ǰ���Ϊû�б�����
//2.��������ӽڵ���һ��û�б����ǣ���ǰ������ʱ����ͷ������ͷ����1
//3.��������ӽڵ���һ��������ͷ����ǰ���Ϊ������
//4.��һ����������ڵ�Ϊû�и��ǣ���ʱ�����ӽڵ��Ǳ����ǣ���ʱ�����ڵ���Ϊ����ͷ


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
	int result = 0;
	int pastorder(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = pastorder(root->left);
		int right = pastorder(root->right);
		//�����ӽڵ㶼�Ǳ�����
		if (left == 0 && right == 0){
			return 2;
		}
		//���Ҫ���������ӽڵ���һ��������ͷǰ��
		//��һ�������left==1��right==0�������Ҫ������ͷ�ͱ�������
		//�����ӽڵ���һ��δ������
		if (left == 2 || right == 2){
			result++;
			return 1;

		}
		//�����ӽڵ���һ��������ͷ
		if (left == 1 || right == 1){
			return 0;
		}

		return -1;
	}

public:
	int minCameraCover(TreeNode* root) {


		//������ڵ�Ϊ��
		if (pastorder(root) == 2){
			result++;
		}
		return result;


	}
};