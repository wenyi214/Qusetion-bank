第一种方法：
将和p串长度相同的s中的子串排序后，放到map中，key是排序后的子串，value是用vector保存的起始位置。
最后将p排序后，返回，map中相同子串的value
排序超过时间限制
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int len1 = p.size();
		int len2 = s.size();
		int start = 0;
		int end = len1 - 1;
		unordered_map<string, vector<int>> mymap;
		while (end < len2){
			//子串排序后加入map中
			string tmp = s.substr(start, end - start + 1);
			sort(tmp.begin(), tmp.end());
			//保存起始位置
			mymap[tmp].push_back(start);
			start++, end++;
		}
		sort(p.begin(), p.end());
		return mymap[p];
	}
};

滑动窗口：
首先说明vector比较"=="，比较的也是字典序，和字符串比较一样，一位大，整个就大。
由题意只有小写字母，开辟两个数组，来保存字符出现次数。然后比较vector，就可以找出相同字符串。
先用一个数组p_arr来保存p中字符出现的次数。
再用一个数组s_arr，来保存s中和字符串p相同长度的子串字符出现的次数。
滑动窗口体现在
s子串长度确定，s_arr[s[start] - 'a']--，s_arr[s[s[end] - 'a']++，再比较两数组


class Solution {
public:
	//vector比较==和字符串一样，按字典序比较
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
		//vector比较也是按字典序比较，和字符串一样
		if (s_arr == p_arr){
			ans.push_back(start);
		}
		//滑动窗口
		while (end < len1){
			//长度确定，更新字符出现次数
			s_arr[s[start++] - 'a']--;
			s_arr[s[end++] - 'a']++;
			if (s_arr == p_arr){
				ans.push_back(start);
			}
		}
		return ans;
	}
};