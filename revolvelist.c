//将链表每个结点移动K个位置
//解题思路：
//先计算链表长度，再将链表首尾相连，再确定从那个结点断开。
//len - k%len - 1
struct ListNode {
	int val;
	struct ListNode *next;
	
};
struct ListNode* rotateRight(struct ListNode* head, int k){
	if (!head || !(head->next)){
		return head;
	}
	int l = 0;
	struct ListNode *tail = head;
	struct ListNode *cur = head;
	while (cur->next){
		l++;
		cur = cur->next;//让cur走到最后一个结点
	}
	int len = l + 1;//计算长度
	cur->next = tail;//首尾相连
	for (int i = 0; i<len - (k%len) - 1; i++){
		tail = tail->next;  //确定哪里断开
	}
	struct ListNode *ass = tail->next;
	tail->next = NULL;
	return ass;
}