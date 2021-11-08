
思路：
先将字符串放到set中去重，主要是查找当前字符串是否可以由其它字符串组成。找到最长的，且字典序最小的。
遍历set中的字符串，查找字符串是否可以由set中的其它字符组合而成。
递归检测是否可以由除自己以外其它字符组合而成，检测前先将当前字符串从set中去除。
set接口count(string str)，如果str在set中返回1，不在返回0。
利用count接口，找当前字符串的[0，i]子串是否在set中，再递归查找[i，word.size()]后面的子串是否可以由set中的字符串组成。
class Solution {
	bool IsWord(const string& word, const unordered_set<string>& s){
		//递归终止条件，最后会找到最后子串，为空
		if (word.size() == 0){
			return true;
		}
		//这里要等于word.size(),长度
		for (int i = 0; i <= word.size(); i++){
			//当word的子串中可以在set中找到，并且后面的子串也可以找set中找到，说明word可以由其它字符串组成
			if (s.count(word.substr(0, i)) && IsWord(word.substr(i), s)){
				return true;
			}
		}
		return false;
	}
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> s(words.begin(), words.end());//去重
		string ans;//结果
		for (auto& ch : s){
			unordered_set<string> tmp = s;
			tmp.erase(ch);//除自己以外
			if (IsWord(ch, tmp)){//查找是否可以由其它字符串组成
				if (ch.size() > ans.size()){//找最长的
					ans = ch;
				}
				if (ch.size() == ans.size()){//字典序最小的
					ans = min(ans, ch);
				}
			}
		}
		return ans;


	}
};

