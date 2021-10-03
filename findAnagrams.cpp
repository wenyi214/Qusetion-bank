��һ�ַ�����
����p��������ͬ��s�е��Ӵ�����󣬷ŵ�map�У�key���������Ӵ���value����vector�������ʼλ�á�
���p����󣬷��أ�map����ͬ�Ӵ���value
���򳬹�ʱ������
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int len1 = p.size();
		int len2 = s.size();
		int start = 0;
		int end = len1 - 1;
		unordered_map<string, vector<int>> mymap;
		while (end < len2){
			//�Ӵ���������map��
			string tmp = s.substr(start, end - start + 1);
			sort(tmp.begin(), tmp.end());
			//������ʼλ��
			mymap[tmp].push_back(start);
			start++, end++;
		}
		sort(p.begin(), p.end());
		return mymap[p];
	}
};

�������ڣ�
����˵��vector�Ƚ�"=="���Ƚϵ�Ҳ���ֵ��򣬺��ַ����Ƚ�һ����һλ�������ʹ�
������ֻ��Сд��ĸ�������������飬�������ַ����ִ�����Ȼ��Ƚ�vector���Ϳ����ҳ���ͬ�ַ�����
����һ������p_arr������p���ַ����ֵĴ�����
����һ������s_arr��������s�к��ַ���p��ͬ���ȵ��Ӵ��ַ����ֵĴ�����
��������������
s�Ӵ�����ȷ����s_arr[s[start] - 'a']--��s_arr[s[s[end] - 'a']++���ٱȽ�������


class Solution {
public:
	//vector�Ƚ�==���ַ���һ�������ֵ���Ƚ�
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int len1 = s.size();
		int len2 = p.size();
		if (len1 < len2){
			return ans;
		}
		int end = 0;
		int start = 0;
		vector<int> s_arr(26, 0), p_arr(26, 0);
		for (int i = 0; i<len2; i++){
			s_arr[s[end++] - 'a']++;
			p_arr[p[i] - 'a']++;
		}
		//vector�Ƚ�Ҳ�ǰ��ֵ���Ƚϣ����ַ���һ��
		if (s_arr == p_arr){
			ans.push_back(start);
		}
		//��������
		while (end < len1){
			//����ȷ���������ַ����ִ���
			s_arr[s[start++] - 'a']--;
			s_arr[s[end++] - 'a']++;
			if (s_arr == p_arr){
				ans.push_back(start);
			}
		}
		return ans;
	}
};