�������ڣ�
���⣺t�п������ظ��Ӵ����ù�ϣ��map��¼�ַ����ָ�����
����Ҫ��������ж�t��s���Ӵ����s�Ӵ��ַ�Ҳ�����ڹ�ϣ��map�����¼������
�ж�t��s �Ӵ����t���ַ�������s�ж�Ӧ�ַ������Ƚϣ�s���ַ�����С��t���ַ�����˵��������s�Ӵ��С�
bool isMembre(){
	//�ж�t���ַ��Ƿ���s�Ӵ���
	for (auto c : t_count){
		//s�Ӵ���Ҳ���ظ���������С�ڵĻ�˵�������ڡ�
		if (s_count[c.first] < c.second){
			return false;
		}
	}
	return true;
}

����ҵ���С�Ӵ���
��s�Ӵ��а���tʱ����߽������ƶ�������(��1)t��Ӧ�ַ���s�Ӵ��еĸ�����������s�ַ�map�ж�Ӧ�ַ������������ж�t�Ƿ���s�Ӵ��С�
class Solution {
private:
	//���ڻ����ظ���Ҫ��¼�ַ�����
	unordered_map<char, int> s_count, t_count;
	bool isMembre(){
		//�ж�t���ַ��Ƿ���s�Ӵ���
		for (auto c : t_count){
			//s�Ӵ���Ҳ���ظ���������С�ڵĻ�˵�������ڡ�
			if (s_count[c.first] < c.second){
				return false;
			}
		}
		return true;

	}
public:
	string minWindow(string s, string t) {
		string ans;
		int len1 = s.size();
		int len2 = t.size();
		if (len1 < len2){
			return ans;
		}

		int l = 0, r = 0;
		//������С����ʱ����ʼλ��
		int ansl = -1;
		int minlen = len1 + 1;
		for (auto& c : t){
			t_count[c]++;
		}
		while (r < len1){
			//��¼s�ַ����ָ���
			s_count[s[r++]]++;
			//����С��������
			//��С��������
			while (isMembre() && l<r){
				//��¼��С����
				if (minlen > r - l){
					minlen = r - l;
					ansl = l;
					//ans=s.substr(l,minlen);
				}
				//l�����ƣ�����t���ַ��ڱ���s�ַ�map�еĸ���
				if (t_count.find(s[l]) != t_count.end()){
					s_count[s[l]]--;
				}
				l++;
			}
		}
		return ansl == -1 ? ans : s.substr(ansl, minlen);
	}
};