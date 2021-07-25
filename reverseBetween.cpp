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
//遍历两次 截成三段，将中间这段反转，再连接起来，需要遍历两遍
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//设置头节点，不同讨论一个结点的情况
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//两个指针
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		//记录分开结点
		ListNode* node1 = nullptr;
		ListNode* oldhead = nullptr;
		ListNode* node2 = nullptr;
		//第一个结点为1  初始化从1开始
		int len = 1;
		//走到left位置
		while (len<left){

			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//记录前一个结点
		node1 = prev;
		//走到right位置
		while (len <= right){
			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//记录right下一个结点
		node2 = cur;
		//断开结点
		prev->next = nullptr;
		oldhead = node1->next;
		node1->next = nullptr;
		//反转left到right
		ListNode* newhead = nullptr;
		while (oldhead){
			ListNode* tmp = oldhead->next;
			oldhead->next = newhead;
			newhead = oldhead;
			oldhead = tmp;
		}
		//找到最后结点
		ListNode *last = newhead;
		while (last->next){
			last = last->next;
		}
		//连接
		node1->next = newhead;
		last->next = node2;

		head = dummy->next;
		delete dummy;
		return head;
	}
};
//遍历一次一次遍历，三指针法
//头插法，找到left位置和left前一个位置
//一个指针指向要插入结点，一个指针指向cherubic结点前一个结点，一个指针指向left前一个结点，进行交换。

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		//设置头节点，不同讨论一个结点的情况
		ListNode *dummy = new ListNode();
		dummy->next = head;
		//两个指针
		ListNode* prev = dummy;
		ListNode* cur = dummy->next;
		//记录分开结点
		ListNode* node1 = nullptr;
		ListNode* oldhead = nullptr;
		ListNode* node2 = nullptr;
		//第一个结点为1  初始化从1开始
		int len = 1;
		//走到left位置
		while (len<left){

			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//记录前一个结点
		node1 = prev;
		//走到right位置
		while (len <= right){
			prev = prev->next;
			cur = cur->next;
			len++;
		}
		//记录right下一个结点
		node2 = cur;
		//断开结点
		prev->next = nullptr;
		oldhead = node1->next;
		node1->next = nullptr;
		//反转left到right
		ListNode* newhead = nullptr;
		while (oldhead){
			ListNode* tmp = oldhead->next;
			oldhead->next = newhead;
			newhead = oldhead;
			oldhead = tmp;
		}
		//找到最后结点
		ListNode *last = newhead;
		while (last->next){
			last = last->next;
		}
		//连接
		node1->next = newhead;
		last->next = node2;

		head = dummy->next;
		delete dummy;
		return head;
	}
};