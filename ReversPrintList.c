//��β��ͷ��ӡ����
//����һ�����������Ⱥ�����ռ䡣������ת���ӡ
//����������ջ�����飬�Ƚ����ݴ���ջ(����)��, top++, �ٽ�ջ�е����ݣ��õ�һ����̬�����С�(������)
//���������ݹ飺�ݹ���ڣ�headΪNULL�����ص���malloc(������Ŀռ䣬�ٽ�ֵ�������飬������룺
struct ListNode {
	int val;
	struct ListNode *next;
	
};
int* reversePrint(struct ListNode* head, int* returnSize){
	//������
	if (!head){
		*returnSize = 0;
		return NULL;
	}
	int top = -1;
	int a[10001];
	while (head){
		top++;
		a[top] = head->val;
		head = head->next;
	}
	int *ass = (int *)malloc(sizeof(int)*(top + 1));//top��0��ʼ������Ҫ��1
	*returnSize = top + 1;
	for (int i = 0; top + 1; i++){
		ass[i] = a[top];
		top--;
	}

	return ass;


	//������
	// if(!head){//�ݹ����
	//     *returnSize=0;
	//     return malloc(sizeof(int)*10000);
	// }

	// int *a=reversePrint(head->next,returnSize);
	// a[(*returnSize)++]=head->val;//�����üӼ�,Ҫ������
	// //*returnSize++;
	// return a;


	//����һ
	// if(!head){
	//     *returnSize=0;
	//     return NULL;
	// }
	// struct ListNode *t=head;
	// int len=0;
	// while(t){
	//     t=t->next;
	//     len++;
	// }
	// int *a=(int *)malloc(sizeof(int)*len);
	// *returnSize=len;
	// struct ListNode *temp;
	// struct ListNode *old=head;
	// struct ListNode *new=NULL;
	// while(old){
	//     temp=old->next;
	//     old->next=new;
	//     new=old;
	//     old=temp;
	// }
	// for(int i=0;i<len;i++){
	//     a[i]=new->val;
	//     new=new->next;
	// }
	// return a;

}