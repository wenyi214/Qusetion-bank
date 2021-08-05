//72. 编辑距离
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		//初始化
		for (int j = 1; j <= len2; j++){
			dp[0][j] = j;

		}
		for (int i = 1; i <= len1; i++){
			dp[i][0] = i;

		}
		//转移方程，都是由前面推出来的，所以从前完后遍历
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				//缩影从0开始 要减1
				if (word1[i - 1] == word2[j - 1]){
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				}
				else{
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		return dp[len1][len2];

	}
};