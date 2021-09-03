//双向循环链表
//中序遍历，
//左指针指向双向链表的上一个
//右指针指向双向链表的下一个
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/
class Solution {
public:
	void GetBoublyList(Node* cur, Node* prev){
		//递归
		// if(cur){
		//     GetBoublyList(cur->left,prev);

		//     cur->left=prev;
		//     if(prev){
		//         prev->right=cur;
		//     }


		//     prev=cur;

		//     GetBoublyList(cur->right,prev);
		// }

		//中序遍历
		stack<Node*> s;
		while (!s.empty() || cur){
			while (cur){
				s.push(cur);

				cur = cur->left;
			}

			cur = s.top();
			s.pop();
			//左指针指向双向链表的前一个
			//右指针指向双向来链表的下一个
			cur->left = prev;
			//由于找不到下一个，只能前一个指向现在这个
			if (prev){
				prev->right = cur;
			}
			prev = cur;
			cur = cur->right;
		}


	}


	Node* treeToDoublyList(Node* root) {
		if (root == nullptr){
			return nullptr;
		}
		Node* cur = root;
		Node *prev = nullptr;

		GetBoublyList(cur, prev);

		//第一个结点连接最后一个结点
		Node *head = root;
		while (head&&head->left){
			head = head->left;

		}
		Node *last = root;
		while (last->right){
			last = last->right;
		}
		head->left = last;
		last->right = head;

		return head;
	}
};