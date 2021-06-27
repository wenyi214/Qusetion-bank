#include<stdio.h>
#include<Windows.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#pragma warning(disable:4996)


struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *MergeSort(struct ListNode *head1, struct ListNode *head2){
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = NULL;
	struct ListNode *cur = dummy;
	while (head1&&head2){
		if (head1->val<head2->val){
			cur->next = head1;
			cur = cur->next;
			head1 = head1->next;
		}
		else{
			cur->next = head2;
			cur = cur->next;
			head2 = head2->next;
		}
	}
	if (head1){
		cur->next = head1;
	}
	if (head2){
		cur->next = head2;
	}
	struct ListNode *ass = dummy->next;
	free(dummy);
	return ass;

}

struct ListNode* sortList(struct ListNode* head){

	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = head;

	//求链表长度
	int len = 0;
	struct ListNode *tail = head;
	while (tail){
		tail = tail->next;
		len++;
	}

	int gap = 1;//归并节数从1开始

	while (gap<len){

		struct ListNode *prev = dummy;
		//要让头节点指向head，如果让cur指向head，head实际没有变
		struct ListNode *cur = dummy->next;
		while (cur){
			//第一节
			struct ListNode *head1 = cur;
			for (int i = 1; i<gap&&cur != NULL&&cur->next != NULL; i++){
				cur = cur->next;
			}
			struct ListNode *temp = cur->next;
			cur->next = NULL;
			cur = temp;
			//第二节
			struct ListNode *head2 = cur;
			for (int i = 1; i<gap&&cur != NULL&&cur->next; i++){
				cur = cur->next;
			}
			if (cur != NULL){
				temp = cur->next;
				cur->next = NULL;
				cur = temp;
			}
			//归并
			struct ListNode *merge = MergeSort(head1, head2);
			prev->next = merge;
			while (prev->next){
				prev = prev->next;
			}

		}
		gap *= 2;
	}
	struct ListNode *ass = dummy->next;
	free(dummy);
	return ass;


}

int main(){

	struct ListNode a;
	struct ListNode b;
	struct ListNode c;
	struct ListNode d;

	a.val = 4;
	a.next = &b;
	b.val = 2;
	b.next = &c;
	c.val = 1;
	c.next = &d;
	d.val = 3;
	d.next = NULL;
	sortList(&a);

	system("pause");
	return 0;
}