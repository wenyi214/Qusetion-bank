//������ÿ������ƶ�K��λ��
//����˼·��
//�ȼ��������ȣ��ٽ�������β��������ȷ�����Ǹ����Ͽ���
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
		cur = cur->next;//��cur�ߵ����һ�����
	}
	int len = l + 1;//���㳤��
	cur->next = tail;//��β����
	for (int i = 0; i<len - (k%len) - 1; i++){
		tail = tail->next;  //ȷ������Ͽ�
	}
	struct ListNode *ass = tail->next;
	tail->next = NULL;
	return ass;
}