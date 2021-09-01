#pragma once
#include<iostream>
using namespace std;


//模板不要与实现分开

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
	//插入
	bool Insert(K val){
		//判断_root
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		Node *cur = _root;
		//找插入位置，一定作为叶节点插入
		Node *prev = nullptr;//记录要插入的结点，就是要插入结点的父节点
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
				cout << "已存在" << endl;
				return false;
			}
		}
		//找到
		cur = new Node(val);
		//判断插入结点的左边还是右边
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
			cout << "不存在" << endl;
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
		cout << "不存在" << endl;
		return nullptr;
	}

	bool Erase(K val){
		if (_root == nullptr){
			return false;
		}
		//找结点
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
				//找到
				if (cur->_left == nullptr&&cur->_right == nullptr){
					//只有一个结点
					if (prev == nullptr){
						delete cur;
						//要将这个置空，不让就会是野指针
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
					//找右子树最小值
					
					Node *tail = cur;
					tail = tail->_right;
					Node *MinRightParent = cur;
					while (tail->_left){
						MinRightParent = tail;
						tail = tail->_left;
					}
					K MinRight = tail->_val;
					//删除右子树最小值结点，左子树肯定为nullptr
					if (MinRightParent->_left == tail){
						MinRightParent->_left = tail->_right;
					}
					else if (MinRightParent->_right == tail){
						MinRightParent->_right = tail->_right;
					}
					else{

					}
					
					delete tail;
					//值替换
					cur->_val = MinRight;
					
					return true;

				}

				
			}
		}
		//没找到
		return false;
	}


	//中序遍历
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