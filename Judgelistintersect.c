struct ListNode {
    int val;
    struct ListNode *next;
};
//假设A长度m，B长度n，A不相交长度为a，B不相交长度为b，相交长度为c。有m = a + c, n = b + c.
//相交：
//假设m<n, 两个指针依次向下走，A走完后走向B，B走完后走向A，
//	则有：a + c + b = b + c + a，两指针都走到了相交点。
//	m>n情况相同，m = n第一次走就同时到相交点。
//不相交：
//走到最后两个都指向空了。
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode *px = headA;
	struct ListNode *py = headB;
	while (px != py){//循环退出条件，都指向相交点或者都指向空(不相交)
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