//147. 对链表进行插入排序
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* insertionSortList(struct ListNode* head){
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = head;
	//控制要插入的值
	struct ListNode *prev1 = dummy;
	struct ListNode *cur1 = dummy->next;
	while (cur1){
		//找到插入位置
		struct ListNode *prev2 = dummy;
		struct ListNode *cur2 = dummy->next;
		//找插入位置
		while (cur2->val <= cur1->val&&cur1 != cur2){
			cur2 = cur2->next;
			prev2 = prev2->next;
		}
		//判断是否插入
		if (cur2->val>cur1->val&&cur1 != cur2){
			//交换
			prev1->next = cur1->next;
			prev2->next = cur1;
			cur1->next = cur2;
			//更新
			cur1 = prev1->next;


		}
		else{
			cur1 = cur1->next;
			prev1 = prev1->next;
		}

	}

	struct ListNode *ass = dummy->next;
	free(dummy);
	return ass;

}