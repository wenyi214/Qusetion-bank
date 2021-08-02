//利用kmp算法，计算出整个字符串的最长前后缀长度，存储在next数组里
//如果 字符串长度len减字符串最长前后缀长度next[len - 1]
//即 len - next[len - 1]，如果可以由重复子串构成， len - next[len - 1]代表一个子串长度，一个周期长度。
//
//如果 len%（ len - next[len - 1]） == 0 说明可以有子字符串，使得可以由子字符串重复构成
//
//还有一种特殊情况，最后最长相同前后缀为0，没有相等的前后缀，肯定没有符合条件的子串

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.size();
		vector<int> next(len, 0);
		//生成next数组，j表示前缀
		int j = 0;
		//i表示后缀，j从0开始，所以从1开始
		for (int i = 1; i<len; i++){
			while (j >= 1 && s[i] != s[j]){
				j = next[j - 1];
			}
			if (s[i] == s[j]){
				j++;
			}
			next[i] = j;
		}

		int x = len - next[len - 1];
		//最长前后缀长度等于0，肯定不能由字串重复构成
		if (x == len){
			return false;
		}
		return len%x == 0;
	}
};