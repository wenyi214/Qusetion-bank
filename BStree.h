#pragma once
#include<iostream>
using namespace std;


//ģ�岻Ҫ��ʵ�ַֿ�

template<class K>
struct BSTreeNode{
	BSTreeNode(K val)
	:_left(nullptr)
	, _right(nullptr)
	, _val(val)
	{}

	BSTreeNode *_left;
	BSTreeNode *_right;

	K _val;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	//����
	bool Insert(K val){
		//�ж�_root
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		Node *cur = _root;
		//�Ҳ���λ�ã�һ����ΪҶ�ڵ����
		Node *prev = nullptr;//��¼Ҫ����Ľ�㣬����Ҫ������ĸ��ڵ�
		while (cur){
			if (val > cur->_val){
				prev = cur;
				cur = cur->_right;
			}
			else if (val < cur->_val){
				prev = cur;
				cur = cur->_left;
			}
			else{
				cout << "�Ѵ���" << endl;
				return false;
			}
		}
		//�ҵ�
		cur = new Node(val);
		//�жϲ��������߻����ұ�
		if (prev->_val > val){
			prev->_left = cur;
		}
		else if (prev->_val < val){
			prev->_right = cur;
		}
		else{

		}
		return true;
	}


	Node *FindNode(K val){
		if (_root == nullptr){
			cout << "������" << endl;
			return nullptr;
		}
		Node *cur = _root;
		while (cur){
			if (val > cur->_val){
				cur = cur->_right;
			}
			else if (val < cur->_val){
				cur = cur->_left;
			}
			else{
				
				return cur;
			}
		}
		cout << "������" << endl;
		return nullptr;
	}

	bool Erase(K val){
		if (_root == nullptr){
			return false;
		}
		//�ҽ��
		Node *cur = _root;
		Node *prev = nullptr;
		while (cur){
			if (val > cur->_val){
				prev = cur;
				cur = cur->_right;
			}
			else if (val < cur->_val){
				prev = cur;
				cur = cur->_left;
			}
			else{
				//�ҵ�
				if (cur->_left == nullptr&&cur->_right == nullptr){
					//ֻ��һ�����
					if (prev == nullptr){
						delete cur;
						//Ҫ������ÿգ����þͻ���Ұָ��
						_root = nullptr;
						return true;
					}

					if (prev->_left == cur){
						prev->_left = nullptr;
					}
					else if (prev->_right == cur){
						prev->_right = nullptr;
					}
					else{

					}
					delete cur;
					return true;
				}
				if (cur->_left&&cur->_right == nullptr){
					if (prev->_left == cur){
						prev->_left = cur->_left;
					}
					else if (prev->_right == cur){
						prev->_right = cur->_left;
					}
					else{

					}
					delete cur;
					return true;
				}
				if (cur->_left==nullptr&&cur->_right){
					if (prev->_left == cur){
						prev->_left = cur->_right;
					}
					else if (prev->_right == cur){
						prev->_right = cur->_right;
					}
					else{

					}
					delete cur;
					return true;
				}
				if (cur->_left&&cur->_right){
					//����������Сֵ
					
					Node *tail = cur;
					tail = tail->_right;
					Node *MinRightParent = cur;
					while (tail->_left){
						MinRightParent = tail;
						tail = tail->_left;
					}
					K MinRight = tail->_val;
					//ɾ����������Сֵ��㣬�������϶�Ϊnullptr
					if (MinRightParent->_left == tail){
						MinRightParent->_left = tail->_right;
					}
					else if (MinRightParent->_right == tail){
						MinRightParent->_right = tail->_right;
					}
					else{

					}
					
					delete tail;
					//ֵ�滻
					cur->_val = MinRight;
					
					return true;

				}

				
			}
		}
		//û�ҵ�
		return false;
	}


	//�������
	void _InNode(Node *root){
		if (root){
			_InNode(root->_left);
			cout << root->_val;
			_InNode(root->_right);
		}
	}

	void InNode(){
		_InNode(_root);
		cout << endl;
	}

private:
	Node *_root = nullptr;
};