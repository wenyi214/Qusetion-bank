//�������������������������
//��ָ��ָ��ǰһ����㣬
//��ָ��ָ��ָ����һ������������ �������ҵ�ǰһ�����Ҳ�����һ����㣬���ǿ��Խ�ǰһ��������ָ��ָ��ǰ��㡣
//
//��һ��ע��㣬ǰһ��ָ��Ҫ�����ã��ݹ鷵��ʱ������prev�����غ�û���¡�
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	//�����������˫ָ�룬�ҵ�ǰһ�����
	void GetDoubleList(TreeNode *root, TreeNode*& prev){//prevҪ�����ã��ݹ鷵��ʱ����֪����һ������ˡ����ǵݹ�ʱ��ֵ
		if (root == nullptr){
			return;
		}
		GetDoubleList(root->left, prev);
		//������ָ��ָ��˫���������һ����㣬��ָ��ָ��˫���������һ�����
		root->left = prev;
		//���ǲ�֪����һ����㣬��������֪����һ�����
		//����һ��������ָ�����ӵ���ǰ��㣬Ҳ�ܵ���Ч����
		if (prev){
			prev->right = root;
		}
		//���½��
		prev = root;

		GetDoubleList(root->right, prev);

	}

	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr){
			return nullptr;
		}
		TreeNode *prev = nullptr;
		GetDoubleList(pRootOfTree, prev);
		//��ͷ�ڵ�
		TreeNode *head = pRootOfTree;
		while (head->left){
			head = head->left;
		}
		return head;
	}
};