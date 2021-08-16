//状态定义：
//
//数组text1以i - 1结尾和数组text2以j - 1结尾的公共不连续最长公共子序列。(这里的最长子序列不是所有里面最长的)，
//
//转移方程：
//
//缩影
//
//当text1[i - 1] == text2[j - 1]时，dp[i][j] = dp[i - 1][j - 1] + 1。text1前i - 2个与text2前j - 2个最长公共子序列个数基础上加1。
//
//当text1[i - 1] != text2[j - 1]时，由两种情况，test1前i - 2个中与test2前j - 1个的最长公共子序列dp[i - 1][j]，test1前i - 1个中与test2前j - 2个的最长公共子序列dp[i][j - 1]，两个中的最大值。
//
//max(dp[i][j - 1], dp[i - 1][j])。
//
//初始化：
//
//dp[i][0] = 0，text1数组没有元素
//
//dp[0][j] = 0，text2数组没有元素
//
//返回值：
//
//所有元素里值最大的


class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.size();
		int len2 = text2.size();
		//初始化
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		int result = 0;
		//转移方程
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				//缩影
				if (text1[i - 1] == text2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
				//得到返回值
				result = max(result, dp[i][j]);
			}
		}
		return result;

	}
};