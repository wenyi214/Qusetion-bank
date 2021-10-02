//动态规划：
//将wordDict单词保存到set哈希表中，查找效率高
//状态定义：
//dp[i]，前i个字符是否能拆分
//转移方程：
//dp[i]状态，遍历前i个字符串，来拆分。j从0~i，看前j个dp[j]是否能拆分 && j到i子串是否能拆分
//初始化：
//dp[0] = true
//返回值：
//dp[s.size()]
	class Solution {
	public:
		//动态规划
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> myset;
			for (auto c : wordDict){
				myset.insert(c);
			}
			int len = s.size();
			vector<bool> dp(len + 1, false);
			dp[0] = true;//初始化，没有字符串可以拆分
			for (int i = 1; i <= s.size(); i++){
				//拆分
				for (int j = 0; j<i; j++){
					//看是否能拆分，看前j个dp[j]是否能拆分 && j到i子串是否能拆分
					//注意使用substr子串
					if (dp[j] && myset.find(s.substr(j, i - j)) != myset.end()){
						dp[i] = true;
						break;
					}
				}
			}
			return dp[len];


		}
	};