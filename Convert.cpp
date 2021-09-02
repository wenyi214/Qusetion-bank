//中序遍历，二叉搜索树，有序
//左指针指向前一个结点，
//右指针指针指向下一个，但是我们 ，可以找到前一个，找不到下一个结点，我们可以将前一个结点的右指针指向当前结点。
//
//有一个注意点，前一个指针要传引用，递归返回时，更新prev，返回后没更新。
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
	//中序遍历，用双指针，找到前一个结点
	void GetDoubleList(TreeNode *root, TreeNode*& prev){//prev要加引用，递归返回时即不知道上一个结点了。还是递归时的值
		if (root == nullptr){
			return;
		}
		GetDoubleList(root->left, prev);
		//处理，左指针指向双向链表的上一个结点，右指针指向双向链表的下一个结点
		root->left = prev;
		//我们不知道下一个结点，但是我们知道上一个结点
		//将上一个结点的右指针连接到当前结点，也能到达效果。
		if (prev){
			prev->right = root;
		}
		//更新结点
		prev = root;

		GetDoubleList(root->right, prev);

	}

	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr){
			return nullptr;
		}
		TreeNode *prev = nullptr;
		GetDoubleList(pRootOfTree, prev);
		//找头节点
		TreeNode *head = pRootOfTree;
		while (head->left){
			head = head->left;
		}
		return head;
	}
};