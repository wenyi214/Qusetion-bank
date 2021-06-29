//从尾到头打印链表
//方法一：计算链表长度后，申请空间。将链表反转后打印
//方法二：用栈，数组，先将数据存入栈(数组)中, top++, 再将栈中的数据，拿到一个动态数组中。(先入后出)
//方法三：递归：递归出口：head为NULL，返回的是malloc(）申请的空间，再将值赋给数组，详见代码：
struct ListNode {
	int val;
	struct ListNode *next;
	
};
int* reversePrint(struct ListNode* head, int* returnSize){
	//方法二
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
	int *ass = (int *)malloc(sizeof(int)*(top + 1));//top从0开始，所以要加1
	*returnSize = top + 1;
	for (int i = 0; top + 1; i++){
		ass[i] = a[top];
		top--;
	}

	return ass;


	//方法三
	// if(!head){//递归出口
	//     *returnSize=0;
	//     return malloc(sizeof(int)*10000);
	// }

	// int *a=reversePrint(head->next,returnSize);
	// a[(*returnSize)++]=head->val;//解引用加加,要带括号
	// //*returnSize++;
	// return a;


	//方法一
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