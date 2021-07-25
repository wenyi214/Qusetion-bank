#include<iostream>

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
//�������� �س����Σ����м���η�ת����������������Ҫ��������
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//����ͷ�ڵ㣬��ͬ����һ���������
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//����ָ��
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		//��¼�ֿ����
		ListNode* node1 = nullptr;
		ListNode* oldhead = nullptr;
		ListNode* node2 = nullptr;
		//��һ�����Ϊ1  ��ʼ����1��ʼ
		int len = 1;
		//�ߵ�leftλ��
		while (len<left){

			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//��¼ǰһ�����
		node1 = prev;
		//�ߵ�rightλ��
		while (len <= right){
			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//��¼right��һ�����
		node2 = cur;
		//�Ͽ����
		prev->next = nullptr;
		oldhead = node1->next;
		node1->next = nullptr;
		//��תleft��right
		ListNode* newhead = nullptr;
		while (oldhead){
			ListNode* tmp = oldhead->next;
			oldhead->next = newhead;
			newhead = oldhead;
			oldhead = tmp;
		}
		//�ҵ������
		ListNode *last = newhead;
		while (last->next){
			last = last->next;
		}
		//����
		node1->next = newhead;
		last->next = node2;

		head = dummy->next;
		delete dummy;
		return head;
	}
};
//����һ��һ�α�������ָ�뷨
//ͷ�巨���ҵ�leftλ�ú�leftǰһ��λ��
//һ��ָ��ָ��Ҫ�����㣬һ��ָ��ָ��cherubic���ǰһ����㣬һ��ָ��ָ��leftǰһ����㣬���н�����

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//����ͷ�ڵ㣬��ͬ����һ���������
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//����ָ��
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		//��¼�ֿ����
		ListNode* node1 = nullptr;
		ListNode* oldhead = nullptr;
		ListNode* node2 = nullptr;
		//��һ�����Ϊ1  ��ʼ����1��ʼ
		int len = 1;
		//�ߵ�leftλ��
		while (len<left){

			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//��¼ǰһ�����
		node1 = prev;
		//�ߵ�rightλ��
		while (len <= right){
			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//��¼right��һ�����
		node2 = cur;
		//�Ͽ����
		prev->next = nullptr;
		oldhead = node1->next;
		node1->next = nullptr;
		//��תleft��right
		ListNode* newhead = nullptr;
		while (oldhead){
			ListNode* tmp = oldhead->next;
			oldhead->next = newhead;
			newhead = oldhead;
			oldhead = tmp;
		}
		//�ҵ������
		ListNode *last = newhead;
		while (last->next){
			last = last->next;
		}
		//����
		node1->next = newhead;
		last->next = node2;

		head = dummy->next;
		delete dummy;
		return head;
	}
};