//����˼·��
//�ҵ���k����㣬������k����㡣����
//���������������
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* swapNodes(struct ListNode* head, int k){
	if (head == NULL){
		return NULL;
	}
	struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
	dummy->next = head;
	struct ListNode *end1 = head;
	struct ListNode *prev1 = dummy;
	//��������K�����
	while (--k){
		prev1 = end1;
		end1 = end1->next;
	}
	struct ListNode *cur1 = end1;
	//�ҵ�����k�����
	struct ListNode *cur2 = head;
	struct ListNode *prev2 = dummy;
	while (end1->next){
		prev2 = cur2;
		cur2 = cur2->next;
		end1 = end1->next;
	}
	//��¼��һ�����
	struct ListNode *next1 = cur1->next;
	struct ListNode *next2 = cur2->next;

	//�������������cur1��cur2ǰһ��
	if (next1 == cur2){
		prev1->next = next1;
		next1->next = cur1;
		cur1->next = next2;
	}
	//cur2��cur1ǰһ��
	else if (next2 == cur1){
		prev2->next = next2;
		next2->next = cur2;
		cur2->next = next1;
	}
	else{
		prev1->next = cur2;
		cur2->next = next1;
		prev2->next = cur1;
		cur1->next = next2;
	}
	struct ListNode *ass = dummy->next;
	free(dummy);
	dummy = NULL;
	return ass;


}

int main(){

	return 0;
}