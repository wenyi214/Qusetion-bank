//状态定义：
//
//dp[i][j]。代表字符串s的前i - 1个字符到前j - 1个字符的最长回文子串长度。
//
//转移方程：
//
//两种情况：
//
//当s[i - 1] == s[j - 1]时，最大长度等于dp[i + 1][j - 1] + 2。字符串s的前i个字符到前j - 2个字符的最长回文子串长度，将上这两个字符个数。
//
//当s[i - 1] != s[j - 1]时，最大长度有两种情况，
//
//不包括s的第j - 1字符时的最长回文串长度，也就是dp[i][j - 1]。
//
//不包括s的第i - 1字符时的最长回文串的长度，也就是dp[i + 1][j]。
//
//dp[i][j]等于两者取最大值。dp[i][j] = max(dp[i][j - 1]，dp[i + 1][j])。
//
//初始化：
//
//当i == j时，指向的是s的同一个字符，此时最大长度为1。
//
//dp[i][i] = 1。
//
//返回值：
//
//dp[1][s.size()]。从第一个字符到最后一个字符最长回文串长度。
//
//注意：遍历顺序，要从后往前遍历，有转移方程，dp[i][j] = max(dp[i][j - 1]，dp[i + 1][j])和dp[i + 1][j - 1] + 2，是由后一排退出前一排的。
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		//可以不连续
		int len = s.size();
		vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
		//初始化
		for (int i = 1; i <= len; i++){
			dp[i][i] = 1;
		}
		//转移方程
		//遍历从后往前遍历
		for (int i = len - 1; i>0; i--){
			for (int j = i + 1; j <= len; j++){
				if (s[i - 1] == s[j - 1]){
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[1][len];


	}
};