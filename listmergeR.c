//递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (!l1) {
		return l2;//返回另外一个后面的值
	}
	if (!l2) {
		return l1;
	}
	struct ListNode* p = NULL;
	if (l1->val < l2->val) {
		p = l1;//如果向就等于它
		p->next = mergeTwoLists(l1->next, l2);
	}
	else {
		p = l2;
		p->next = mergeTwoLists(l1, l2->next);
	}
	return p;
}
//非递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}
	struct ListNode *front = NULL;
	struct ListNode *rear = NULL;
	struct ListNode *temp;
	struct ListNode *px = l1;
	struct ListNode *py = l2;
	while (px&&py){
		if (px->val <= py->val){
			temp = px->next;
			px->next = NULL;
			if (front == NULL&&rear == NULL){
				front = px;
				rear = px;
			}
			else{
				rear->next = px;
				rear = rear->next;
			}
			px = temp;
		}
		else{
			temp = py->next;
			py->next = NULL;
			if (front == NULL&&rear == NULL){
				front = py;
				rear = py;
			}
			else{
				rear->next = py;
				rear = rear->next;
			}
			py = temp;
		}
	}
	if (!px){
		rear->next = py;
	}
	else{
		rear->next = px;
	}
	return front;
}