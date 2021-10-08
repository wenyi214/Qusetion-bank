//��O(1)ʱ����������ֲ�����ʹ��˫������������ջ����¼�Ƿ񾭳�ʹ�ã����ұ���valueֵ
//˫����������������㣬һ��ͷ�ڵ㣬һ��Ϊβ��㣬����β�ڵ���ǲ�����ʹ�õĽ�㣬����ͷ�ڵ��Ǹս������ʹ�õĽ�㡣
//��˫������Ҳ��Ҫ����key��value����Ϊβɾʱ����ͨ���������ҽ�㣬��map��Ҳ��Ҫɾ����ֵ����Ҫkeyֵ��
//˫������ɾ�������ӽ�㷽�㣬����ǰһ����㡣
//��map������key�ͽ�㡣
//ͨ��map����key��valueʱ�临�Ӷ���O(1)��ֻ��˫��������ҪO(N)ʱ�临�Ӷȣ�mapֻ�Ǻ���key��Ӧ��value
//��ȡֵget������
//��map����key�����ڣ�����value�����ҽ���key��㣬�ƶ����ʼ��
//put������
//�����ڣ�ֱ��newһ����㣬����˫������ͷ�������ҹ����ֵ�Բ���map
//���ڣ���ý�㣬�޸�ֵ���ƶ�������ͷ����
//������������˫������βɾ�����keyֵɾ��map�еļ�ֵ�ԡ�
class LRUCache {
	//˫����������key��value
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
	//�����¼�Ƿ񾭳�ʹ�ã�map����O(1)ʱ��ɾ��
	unordered_map<int, DoubleList *> _map;
	//����ͷ��β�ڵ㣬����β���ǲ�����ʹ�õģ�����ͷ�Ǿ���ʹ�õ�
	DoubleList *_head;
	DoubleList *_tail;
	//����
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
		if (it != _map.end()){//�������
			int res = it->second->_val;
			DoubleList *node = it->second;

			RemovetoFront(node);//������ƶ�����ʼ���
			//_map.erase(it);
			return res;
		}
		return -1;

	}

	void put(int key, int value) {
		//�����
		unordered_map<int, DoubleList *>::iterator it = _map.find(key);
		//�����ڣ�ֱ�Ӳ���һ����㣬����ͷ�ڵ㴦
		if (it == _map.end()){
			DoubleList *node = new DoubleList(key, value);
			PushFront(node);
			_map.insert(make_pair(key, node));
		}
		else{//���ڣ��޸�ֵ���ƶ���ͷ�ڵ�

			DoubleList *node = it->second;
			node->_val = value;
			RemovetoFront(node);
		}
		//�Ƿ񳬹������������ɾ��������ʹ�ý�㣬βɾ
		if (_cap < _map.size()){
			DoubleList *node = _tail->_prev;//������һ�����
			int k = node->_key;
			_map.erase(k);
			RemoveTail();//βɾ
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