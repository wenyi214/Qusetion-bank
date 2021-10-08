只是保存前缀会相同的字符串，如果前缀不相同，会形成一个新的分支。
起始map保存链表或者树的头节点
前缀树：
保存字符的树，结点是自身
需要用到查找，用map来保存，key为字符，value为结点。，key来保存字符，value保存同一字符串的字符
多个字符串时，相同的前缀会用到相同的结点。
还需要一个变量isEnd来保存是否走到了字符串结尾。
插入结点：
先保存当前的结点，如果在map中对应字符的second为空，说明没有该字符，创建新节点，连接，走到下一个结点。
到最后将isEnd设为true
void insert(string word) {
	//保存当前结点
	Trie *head = this;
	for (auto ch : word){
		//为空，说明还没有过该字符
		if (head->m[ch] == nullptr){
			//一个字符串，都会有一个新的map，head指向下一个结点，新map里只保存了一个字符
			//所以可以有重复的。
			head->m[ch] = new Trie();
		}
		//走到下一个结点
		head = head->m[ch];
	}
	head->isEnd = true;

}

查找：
保存当前结点，在map中找对应字符，看value是否为空，为空说明没有该字符
走到要找的字符串最后，判断是否时结点的isEnd是否为结尾。

bool search(string word) {
	//当前结点
	Trie *head = this;
	for (auto ch : word){
		//为空说明没有该字符
		if (head->m[ch] == nullptr){
			return false;
		}
		//往后走
		head = head->m[ch];
	}
	//判断是否是最后
	return head->isEnd;

}

查找前缀：
bool startsWith(string prefix) {
	//保存当前结点
	Trie *head = this;
	for (auto ch : prefix){
		//如果为空，说明没有该字符，返回false
		if (head->m[ch] == nullptr){
			return false;
		}
		//走到洗一个结点
		head = head->m[ch];
	}
	//说明有该前缀
	return true;

}


全部代码：
class Trie {
private:
	unordered_map<char, Trie*> m;//保存字符串的每一个字符，每一个字符都会有一个Trie，前缀相同，可以共用相同结点
	bool isEnd = false;//字符串是否结束
public:
	Trie() {

	}

	void insert(string word) {
		//保存当前结点
		Trie *head = this;
		for (auto ch : word){
			//为空，说明还没有过该字符
			if (head->m[ch] == nullptr){
				//一个字符串，都会有一个新的map，head指向下一个结点，新map里只保存了一个字符
				//所以可以有重复的。
				head->m[ch] = new Trie();
			}
			//走到下一个结点
			head = head->m[ch];
		}
		head->isEnd = true;

	}

	bool search(string word) {
		//当前结点
		Trie *head = this;
		for (auto ch : word){
			//为空说明没有该字符
			if (head->m[ch] == nullptr){
				return false;
			}
			//往后走
			head = head->m[ch];
		}
		//判断是否是最后
		return head->isEnd;

	}

	bool startsWith(string prefix) {
		//保存当前结点
		Trie *head = this;
		for (auto ch : prefix){
			//如果为空，说明没有该字符，返回false
			if (head->m[ch] == nullptr){
				return false;
			}
			//走到洗一个结点
			head = head->m[ch];
		}
		//说明有该前缀
		return true;

	}
};