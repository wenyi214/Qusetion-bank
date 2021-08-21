//状态定义：
//
//以下标i - 1结尾的字符串s，与下标j - 1结尾的字符串j - 1，相同元素的个数。dp[i][j]。为什么是i - 1和j - 1，字符串缩影。
//
//转移方程：
//
//如果s[i - 1] == t[j - 1]，dp[i][j] = dp[i - 1][j - 1] + 1，多了一个相同元素s[i - 1]与t[j - 1]。
//
//如果s[i - 1] != t[j - 1]，要将t[j - 1]删掉，比较s[i - 1]与t[j - 2]，即dp[i][j] = dp[i][j - 1]。
//
//初始化：
//
//dp[i][0] = 0，t没有元素，相同子序列为0
//
//dp[0][j] = 0，s没有元素，相同子序列为0
//
//返回值：
//
//dp[s.size()][t.size()] == s.size()，相等元素个数等于s个元素个数，说明s的元素在t里。


class Solution {
public:
	bool isSubsequence(string s, string t) {
		int len1 = s.size();
		int len2 = t.size();
		//初始化
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		//转移方程
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s[i - 1] == t[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = dp[i][j - 1];
				}

			}

		}
		return dp[len1][len2] == len1;

	}
};