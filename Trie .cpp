ֻ�Ǳ���ǰ׺����ͬ���ַ��������ǰ׺����ͬ�����γ�һ���µķ�֧��
��ʼmap���������������ͷ�ڵ�
ǰ׺����
�����ַ����������������
��Ҫ�õ����ң���map�����棬keyΪ�ַ���valueΪ��㡣��key�������ַ���value����ͬһ�ַ������ַ�
����ַ���ʱ����ͬ��ǰ׺���õ���ͬ�Ľ�㡣
����Ҫһ������isEnd�������Ƿ��ߵ����ַ�����β��
�����㣺
�ȱ��浱ǰ�Ľ�㣬�����map�ж�Ӧ�ַ���secondΪ�գ�˵��û�и��ַ��������½ڵ㣬���ӣ��ߵ���һ����㡣
�����isEnd��Ϊtrue
void insert(string word) {
	//���浱ǰ���
	Trie *head = this;
	for (auto ch : word){
		//Ϊ�գ�˵����û�й����ַ�
		if (head->m[ch] == nullptr){
			//һ���ַ�����������һ���µ�map��headָ����һ����㣬��map��ֻ������һ���ַ�
			//���Կ������ظ��ġ�
			head->m[ch] = new Trie();
		}
		//�ߵ���һ�����
		head = head->m[ch];
	}
	head->isEnd = true;

}

���ң�
���浱ǰ��㣬��map���Ҷ�Ӧ�ַ�����value�Ƿ�Ϊ�գ�Ϊ��˵��û�и��ַ�
�ߵ�Ҫ�ҵ��ַ�������ж��Ƿ�ʱ����isEnd�Ƿ�Ϊ��β��

bool search(string word) {
	//��ǰ���
	Trie *head = this;
	for (auto ch : word){
		//Ϊ��˵��û�и��ַ�
		if (head->m[ch] == nullptr){
			return false;
		}
		//������
		head = head->m[ch];
	}
	//�ж��Ƿ������
	return head->isEnd;

}

����ǰ׺��
bool startsWith(string prefix) {
	//���浱ǰ���
	Trie *head = this;
	for (auto ch : prefix){
		//���Ϊ�գ�˵��û�и��ַ�������false
		if (head->m[ch] == nullptr){
			return false;
		}
		//�ߵ�ϴһ�����
		head = head->m[ch];
	}
	//˵���и�ǰ׺
	return true;

}


ȫ�����룺
class Trie {
private:
	unordered_map<char, Trie*> m;//�����ַ�����ÿһ���ַ���ÿһ���ַ�������һ��Trie��ǰ׺��ͬ�����Թ�����ͬ���
	bool isEnd = false;//�ַ����Ƿ����
public:
	Trie() {

	}

	void insert(string word) {
		//���浱ǰ���
		Trie *head = this;
		for (auto ch : word){
			//Ϊ�գ�˵����û�й����ַ�
			if (head->m[ch] == nullptr){
				//һ���ַ�����������һ���µ�map��headָ����һ����㣬��map��ֻ������һ���ַ�
				//���Կ������ظ��ġ�
				head->m[ch] = new Trie();
			}
			//�ߵ���һ�����
			head = head->m[ch];
		}
		head->isEnd = true;

	}

	bool search(string word) {
		//��ǰ���
		Trie *head = this;
		for (auto ch : word){
			//Ϊ��˵��û�и��ַ�
			if (head->m[ch] == nullptr){
				return false;
			}
			//������
			head = head->m[ch];
		}
		//�ж��Ƿ������
		return head->isEnd;

	}

	bool startsWith(string prefix) {
		//���浱ǰ���
		Trie *head = this;
		for (auto ch : prefix){
			//���Ϊ�գ�˵��û�и��ַ�������false
			if (head->m[ch] == nullptr){
				return false;
			}
			//�ߵ�ϴһ�����
			head = head->m[ch];
		}
		//˵���и�ǰ׺
		return true;

	}
};