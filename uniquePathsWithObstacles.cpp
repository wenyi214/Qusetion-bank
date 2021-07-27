class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		//记录行列
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		//初始化
		for (int i = 0; i<row; i++){
			if (obstacleGrid[i][0] != 1){
				dp[i][0] = 1;
			}
			else{
				break;
			}
		}
		for (int i = 0; i<col; i++){
			if (obstacleGrid[0][i] != 1){
				dp[0][i] = 1;
			}
			else{
				break;
			}
		}
		//转移方程
		for (int i = 1; i<row; i++){
			for (int j = 1; j<col; j++){
				if (obstacleGrid[i][j] != 1){
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		return dp[row - 1][col - 1];

	}
};