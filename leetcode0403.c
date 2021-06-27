//面试题 04.03.特定深度节点链表
//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct ListNode {
    int val;
    struct ListNode *next;
};



/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int Getdepth(struct TreeNode *tree){//求树深度
	if (tree == NULL){
		return 0;
	}
	int ld = Getdepth(tree->left);
	int rd = Getdepth(tree->right);
	int d = ld>rd ? ld : rd;
	return d + 1;
}
int Getnodenum(struct TreeNode *tree){//求结点个数
	if (tree == NULL){
		return 0;
	}
	return Getnodenum(tree->left) + Getnodenum(tree->right) + 1;
}

struct ListNode *Getlistnode(int x){//创建一个新结点
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
	if (!tree){
		*returnsize = 0；
			return NULL;
	}
	//创建一个保存链表头节点的数组
	*returnSize = Getdepth(tree);
	struct ListNode **ass = (struct ListNode **)malloc(sizeof(struct ListNode *)*(*returnSize));
	//创建一个保存树节点的队列
	int node = Getnodenum(tree);
	struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*node);

	int front = 0;
	int rear = 0;
	int j = 0;
	queue[rear++] = tree;
	//创建一个头节点，好连接链表
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = NULL;
	while (front != rear){
		int oldfront = front;//记录好之前放入了几个结点
		int oldrear = rear;

		dummy->next = NULL;
		struct ListNode *cur = dummy;
		for (int i = 0; i<oldrear - oldfront; i++){//将之前放入的结点的子节点全部繁缛队列

			tree = queue[front++];//在之前形成链表
			cur->next = Getlistnode(tree->val);
			cur = cur->next;

			if (tree->left){
				queue[rear++] = tree->left;
			}
			if (tree->right){
				queue[rear++] = tree->right;
			}
		}
		ass[j++] = dummy->next;

	}
	free(dummy);
	return ass;


}