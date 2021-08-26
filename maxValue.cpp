//动态规划：
//状态定义：
//走到i，j处的最大价值dp[i][j]
//转移方程：
//由于只能向右和向下走，加大价值等于该位置，上面的最大价值和右边最大价值的最大值，加上当前位置的价值
//dp[i][j] = max(dp[i - 1][j]，dp[i][j - 1]) + grids[i][j]
//初始化：
//第一排只能一直向右走
//第一列只能一直向下走
//for (int i = 1; i<len1; i++){
//	dp[i][0] = dp[i - 1][0] + grid[i][0];
//}
//for (int j = 1; j<len2; j++){
//	dp[0][j] = dp[0][j - 1] + grid[0][j];
//}
//返回值
//dp[grid.size][grid[0].size]
	class Solution {
	public:
		int maxValue(vector<vector<int>>& grid) {
			int len1 = grid.size();
			int len2 = grid[0].size();

			vector<vector<int>> dp(len1, vector<int>(len2, 0));
			dp[0][0] = grid[0][0];
			//初始化
			for (int i = 1; i<len1; i++){
				dp[i][0] = dp[i - 1][0] + grid[i][0];
			}
			for (int j = 1; j<len2; j++){
				dp[0][j] = dp[0][j - 1] + grid[0][j];
			}


			for (int i = 1; i<len1; i++){
				for (int j = 1; j<len2; j++){
					//转移方程
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}

			return dp[len1 - 1][len2 - 1];

		}
	};