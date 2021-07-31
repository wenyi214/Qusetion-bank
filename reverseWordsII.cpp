class Solution {
public:
	//�ռ临�Ӷ�O(n),ʱ�临�Ӷ�O(n^2)
	string reverseWords(string s) {
		string res;
		int len = s.size();
		int pos = 0;
		for (int i = len - 1; i >= 0; i = pos - 1){
			//ȡ������Ŀո�
			while (i >= 0 && s[i] == ' '){
				i--;
			}
			//�����ʼ�пո�ֱ�ӻ��ߵ��ʼ��ֱ���˳�
			if (i<0){
				break;
			}
			//��ǰ���ҿո�
			pos = s.rfind(' ', i);
			int j = pos + 1;
			//�ŵ�������
			while (j <= i){
				res += s[j++];
			}
			//û�ҵ��ո�Ͳ��ӿո�
			if (pos != string::npos)
				res += ' ';
		}
		if (s[0] == ' '){
			res.pop_back();
		}
		return res;
	}
};

//�Ż�
//O(1)�ռ临�Ӷȣ�
class Solution {
public:
	string reverseWords(string s) {
		int fast = 0;
		int slow = 0;
		int len = s.size();
		//ȡ��ǰ��Ŀո�
		while (fast<len&&s[fast] == ' '){
			fast++;
		}
		//ȡ���м����ո�
		while (fast<len){
			if (fast - 1>0 && s[fast - 1] == s[fast] && s[fast] == ' '){
				fast++;
			}
			else{
				s[slow++] = s[fast++];
			}
		}
		//ȡ������Ŀո�
		//ԭ�ַ��������пո񣬻������ַ��������һ���ո�ȥ��
		if (s[slow - 1] == ' '){
			s.resize(slow - 1);
		}
		//ԭ�ַ�������û�ո�
		else{
			s.resize(slow);
		}
		//���巴ת
		int num = s.size();
		int left = 0;
		int right = num - 1;
		while (left<right){
			swap(s[left++], s[right--]);
		}

		//�ַ���ת
		for (int i = 0; i<num; i++){
			int j = i;
			while (j < num&&s[j] != ' '){
				j++;
			}
			int left = i;
			int right = j - 1;
			while (left<right){
				swap(s[left++], s[right--]);
			}
			i = j;
		}

		return s;

	}
};