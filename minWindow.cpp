滑动窗口：
题意：t中可能有重复子串，用哈希表map记录字符出现个数。
最重要的是如何判断t在s的子串里，将s子串字符也保存在哈希表map里，并记录个数。
判断t在s 子串里，将t中字符个数与s中对应字符个数比较，s中字符个数小于t中字符个数说明，不在s子串中。
bool isMembre(){
	//判断t中字符是否都在s子串里
	for (auto c : t_count){
		//s子串里也有重复，所以是小于的话说明不存在。
		if (s_count[c.first] < c.second){
			return false;
		}
	}
	return true;
}

如何找到最小子串。
当s子串中包含t时，左边界向右移动，更新(减1)t对应字符在s子串中的个数，即保存s字符map中对应字符个数。持续判断t是否还在s子串中。
class Solution {
private:
	//由于会有重复，要记录字符个数
	unordered_map<char, int> s_count, t_count;
	bool isMembre(){
		//判断t中字符是否都在s子串里
		for (auto c : t_count){
			//s子串里也有重复，所以是小于的话说明不存在。
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
		//保存最小长度时的起始位置
		int ansl = -1;
		int minlen = len1 + 1;
		for (auto& c : t){
			t_count[c]++;
		}
		while (r < len1){
			//记录s字符出现个数
			s_count[s[r++]]++;
			//找最小滑动窗口
			//缩小滑动窗口
			while (isMembre() && l<r){
				//记录最小长度
				if (minlen > r - l){
					minlen = r - l;
					ansl = l;
					//ans=s.substr(l,minlen);
				}
				//l向右移，更新t中字符在保存s字符map中的个数
				if (t_count.find(s[l]) != t_count.end()){
					s_count[s[l]]--;
				}
				l++;
			}
		}
		return ansl == -1 ? ans : s.substr(ansl, minlen);
	}
};