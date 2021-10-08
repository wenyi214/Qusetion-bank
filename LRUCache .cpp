//在O(1)时间内完成两种操作，使用双向链表来代替栈，记录是否经常使用，并且保存value值
//双向链表设置连个结点，一个头节点，一个为尾结点，连接尾节点的是不经常使用的结点，靠经头节点是刚进入或者使用的结点。
//在双向链表也需要保存key和value，因为尾删时，是通过链表来找结点，在map中也需要删除该值，需要key值。
//双向链表删除和增加结点方便，好找前一个结点。
//用map来保存key和结点。
//通过map来找key，value时间复杂度是O(1)，只用双向链表，需要O(N)时间复杂度，map只是好找key对应的value
//获取值get操作：
//在map中找key，存在，返回value，并且将该key结点，移动到最开始。
//put操作：
//不存在：直接new一个结点，插入双向链表头部，并且构造键值对插入map
//存在，获得结点，修改值，移动到链表头部。
//超过容量，将双向链表尾删，获得key值删除map中的键值对。
class LRUCache {
	//双向链表，保存key和value
	struct DoubleList{
		int _key;
		int _val;
		DoubleList *_prev;
		DoubleList *_next;
		DoubleList(int key = 0, int val = 0)
			:_key(key)
			, _val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

private:
	//链表记录是否经常使用，map方便O(1)时间删除
	unordered_map<int, DoubleList *> _map;
	//链表头和尾节点，靠近尾的是不经常使用的，靠近头是经常使用的
	DoubleList *_head;
	DoubleList *_tail;
	//容量
	size_t _cap;

public:
	LRUCache(int capacity) {
		_cap = capacity;

		_head = new DoubleList();
		_tail = new DoubleList();
		_head->_prev = _tail;
		_head->_next = _tail;
		_tail->_prev = _head;
		_tail->_next = _head;
	}

	int get(int key) {

		unordered_map<int, DoubleList *>::iterator it = _map.find(key);
		if (it != _map.end()){//如果存在
			int res = it->second->_val;
			DoubleList *node = it->second;

			RemovetoFront(node);//将结点移动到开始结点
			//_map.erase(it);
			return res;
		}
		return -1;

	}

	void put(int key, int value) {
		//先添加
		unordered_map<int, DoubleList *>::iterator it = _map.find(key);
		//不存在，直接插入一个结点，放在头节点处
		if (it == _map.end()){
			DoubleList *node = new DoubleList(key, value);
			PushFront(node);
			_map.insert(make_pair(key, node));
		}
		else{//存在，修改值后，移动到头节点

			DoubleList *node = it->second;
			node->_val = value;
			RemovetoFront(node);
		}
		//是否超过容量，查过，删除不经常使用结点，尾删
		if (_cap < _map.size()){
			DoubleList *node = _tail->_prev;//获得最后一个结点
			int k = node->_key;
			_map.erase(k);
			RemoveTail();//尾删
		}


	}
	void RemovetoFront(DoubleList *node){
		DoubleList *prev = node->_prev;
		DoubleList *next = node->_next;
		prev->_next = next;
		next->_prev = prev;

		DoubleList *cur = _head->_next;
		_head->_next = node;
		node->_prev = _head;
		node->_next = cur;
		cur->_prev = node;
	}

	void RemoveNode(DoubleList *node){
		DoubleList *prev = node->_prev;
		DoubleList *next = node->_next;
		prev->_next = next;
		next->_prev = next;
		delete node;
	}
	void RemoveTail(){
		DoubleList *node = _tail->_prev;
		DoubleList *prev = node->_prev;
		prev->_next = _tail;
		_tail->_prev = prev;
		delete node;
	}
	void PushFront(DoubleList *node){
		DoubleList *next = _head->_next;
		_head->_next = node;
		node->_prev = _head;
		next->_prev = node;
		node->_next = next;

	}
};