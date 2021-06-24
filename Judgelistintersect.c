struct ListNode {
    int val;
    struct ListNode *next;
};
//����A����m��B����n��A���ཻ����Ϊa��B���ཻ����Ϊb���ཻ����Ϊc����m = a + c, n = b + c.
//�ཻ��
//����m<n, ����ָ�����������ߣ�A���������B��B���������A��
//	���У�a + c + b = b + c + a����ָ�붼�ߵ����ཻ�㡣
//	m>n�����ͬ��m = n��һ���߾�ͬʱ���ཻ�㡣
//���ཻ��
//�ߵ����������ָ����ˡ�
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode *px = headA;
	struct ListNode *py = headB;
	while (px != py){//ѭ���˳���������ָ���ཻ����߶�ָ���(���ཻ)
		if (px == NULL){
			px = headB;
		}
		else{
			px = px->next;
		}
		if (py == NULL){
			py = headA;
		}
		else{
			py = py->next;
		}
	}
	return px;
}