//147. ��������в�������
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* insertionSortList(struct ListNode* head){
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = head;
	//����Ҫ�����ֵ
	struct ListNode *prev1 = dummy;
	struct ListNode *cur1 = dummy->next;
	while (cur1){
		//�ҵ�����λ��
		struct ListNode *prev2 = dummy;
		struct ListNode *cur2 = dummy->next;
		//�Ҳ���λ��
		while (cur2->val <= cur1->val&&cur1 != cur2){
			cur2 = cur2->next;
			prev2 = prev2->next;
		}
		//�ж��Ƿ����
		if (cur2->val>cur1->val&&cur1 != cur2){
			//����
			prev1->next = cur1->next;
			prev2->next = cur1;
			cur1->next = cur2;
			//����
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