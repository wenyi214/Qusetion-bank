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
		//����һ��ͷ�ڵ�ȽϺ�
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//����ָ��
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		while (cur){
			//���ɾ�����
			if (cur->val == val){
				ListNode *next = cur->next;

				prev->next = next;
				delete cur;
				//cur������
				cur = next;

			}
			//���ȸ��½��
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