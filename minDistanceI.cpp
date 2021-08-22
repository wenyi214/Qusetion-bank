//状态定义：
//
//使得word1[i - 1]等于word2[j - 1]的最小步数。
//
//转移方程：
//
//两种情况：
//
//当word1[i - 1] == word[j - 1]时，不用删除字符，即不需要操作。dp[i][j] = dp[i - 1][j - 1]。
//
//当word1[i - 1] != word[j - 1]时，需要删除字符。三种情况：
//
//1.删除word1的第i - 1字符，dp[i - 1][j] + 1。加1是因为做删除操作步数加1。
//
//2.删除word2的第j - 1字符，dp[i][j - ] + 1
//
//3.删除word1的第i - 1字符，删除word2的第j - 1字符，dp[i - 1][j - 1] + 2。做两次删除操作。
//
//最小操作次数：dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 2)
//
//初始化：
//
//dp[0][j] = j，word1没有字符，需要将word2字符全部删除。
//
//dp[i][0] = i，word2没有字符，需要将word1字符全部删除。
//
//返回值：
//
//dp[word1.size()][word2.size()]。
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		//初始化
		for (int i = 1; i <= len1; i++){
			dp[i][0] = i;
		}
		for (int j = 0; j <= len2; j++){
			dp[0][j] = j;
		}
		//转移方程
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (word1[i - 1] == word2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 2);
				}
			}
		}
		return dp[len1][len2];

	}
};