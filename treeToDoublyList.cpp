//˫��ѭ������
//���������
//��ָ��ָ��˫���������һ��
//��ָ��ָ��˫���������һ��
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
		//�ݹ�
		// if(cur){
		//     GetBoublyList(cur->left,prev);

		//     cur->left=prev;
		//     if(prev){
		//         prev->right=cur;
		//     }


		//     prev=cur;

		//     GetBoublyList(cur->right,prev);
		// }

		//�������
		stack<Node*> s;
		while (!s.empty() || cur){
			while (cur){
				s.push(cur);

				cur = cur->left;
			}

			cur = s.top();
			s.pop();
			//��ָ��ָ��˫�������ǰһ��
			//��ָ��ָ��˫�����������һ��
			cur->left = prev;
			//�����Ҳ�����һ����ֻ��ǰһ��ָ���������
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

		//��һ������������һ�����
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