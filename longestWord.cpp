
˼·��
�Ƚ��ַ����ŵ�set��ȥ�أ���Ҫ�ǲ��ҵ�ǰ�ַ����Ƿ�����������ַ�����ɡ��ҵ���ģ����ֵ�����С�ġ�
����set�е��ַ����������ַ����Ƿ������set�е������ַ���϶��ɡ�
�ݹ����Ƿ�����ɳ��Լ����������ַ���϶��ɣ����ǰ�Ƚ���ǰ�ַ�����set��ȥ����
set�ӿ�count(string str)�����str��set�з���1�����ڷ���0��
����count�ӿڣ��ҵ�ǰ�ַ�����[0��i]�Ӵ��Ƿ���set�У��ٵݹ����[i��word.size()]������Ӵ��Ƿ������set�е��ַ�����ɡ�
class Solution {
	bool IsWord(const string& word, const unordered_set<string>& s){
		//�ݹ���ֹ�����������ҵ�����Ӵ���Ϊ��
		if (word.size() == 0){
			return true;
		}
		//����Ҫ����word.size(),����
		for (int i = 0; i <= word.size(); i++){
			//��word���Ӵ��п�����set���ҵ������Һ�����Ӵ�Ҳ������set���ҵ���˵��word�����������ַ������
			if (s.count(word.substr(0, i)) && IsWord(word.substr(i), s)){
				return true;
			}
		}
		return false;
	}
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> s(words.begin(), words.end());//ȥ��
		string ans;//���
		for (auto& ch : s){
			unordered_set<string> tmp = s;
			tmp.erase(ch);//���Լ�����
			if (IsWord(ch, tmp)){//�����Ƿ�����������ַ������
				if (ch.size() > ans.size()){//�����
					ans = ch;
				}
				if (ch.size() == ans.size()){//�ֵ�����С��
					ans = min(ans, ch);
				}
			}
		}
		return ans;


	}
};

