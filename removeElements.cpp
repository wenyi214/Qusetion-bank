/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr){
			return head;
		}
		//设置一个头节点比较好
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//两个指针
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		while (cur){
			//相等删除结点
			if (cur->val == val){
				ListNode *next = cur->next;

				prev->next = next;
				delete cur;
				//cur结点更新
				cur = next;

			}
			//不等更新结点
			else{
				prev = prev->next;
				cur = cur->next;
			}
		}
		head = dummy->next;
		delete dummy;
		return head;

	}
};