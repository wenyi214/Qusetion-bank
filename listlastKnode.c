struct ListNode{
	int val;
	struct ListNode *next;
};
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	struct ListNode* q = head;
	struct ListNode* p = head;
	int i = 0;
	while (i < k){
		q = q->next;
		i++;
	}
	while (q != NULL){
		q = q->next;
		p = p->next;
	}
	return p;
}