class Solution {
public:
	int uniquePaths(int m, int n) {
		//保存结果数组加初始化
		vector<vector<int>> dp(m, vector<int>(n, 1));
		//转移方程
		for (int i = 1; i<m; i++){
			for (int j = 1; j<n; j++){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];

	}
};