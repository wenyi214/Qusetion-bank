//������ 04.03.�ض���Ƚڵ�����
//����һ�ö����������һ���㷨����������ĳһ��������нڵ���������磬��һ���������Ϊ D����ᴴ���� D ������������һ������������ȵ���������顣
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

int Getdepth(struct TreeNode *tree){//�������
	if (tree == NULL){
		return 0;
	}
	int ld = Getdepth(tree->left);
	int rd = Getdepth(tree->right);
	int d = ld>rd ? ld : rd;
	return d + 1;
}
int Getnodenum(struct TreeNode *tree){//�������
	if (tree == NULL){
		return 0;
	}
	return Getnodenum(tree->left) + Getnodenum(tree->right) + 1;
}

struct ListNode *Getlistnode(int x){//����һ���½��
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

struct ListNode** listOfDepth(struct TreeNode* tree, int* returnSize){
	if (!tree){
		*returnsize = 0��
			return NULL;
	}
	//����һ����������ͷ�ڵ������
	*returnSize = Getdepth(tree);
	struct ListNode **ass = (struct ListNode **)malloc(sizeof(struct ListNode *)*(*returnSize));
	//����һ���������ڵ�Ķ���
	int node = Getnodenum(tree);
	struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*node);

	int front = 0;
	int rear = 0;
	int j = 0;
	queue[rear++] = tree;
	//����һ��ͷ�ڵ㣬����������
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = NULL;
	while (front != rear){
		int oldfront = front;//��¼��֮ǰ�����˼������
		int oldrear = rear;

		dummy->next = NULL;
		struct ListNode *cur = dummy;
		for (int i = 0; i<oldrear - oldfront; i++){//��֮ǰ����Ľ����ӽڵ�ȫ�����ȶ���

			tree = queue[front++];//��֮ǰ�γ�����
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