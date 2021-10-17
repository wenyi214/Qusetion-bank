我的思路：
状态定义：[i，j]的最大正方形面积。
只是利用到了[i，j]左上角

当前位置为0，dp[i][j] = 0
当前位置为1，并且左上角由最大正方形存在，即面积不为0，求出正方形最长边长。然后求面积
初始化：
dp[0][i] 为当前值
dp[i][0] 为当前值
class Solution {
private:
	//求边长最大长度
	int Judge(vector<vector<char>>& matrix, int i, int j, int len){
		int row = 0;
		int col = 0;
		int x = 0;
		for (int k = 1; k <= len; k++){
			if (matrix[i - k][j] == '1'){
				row++;
			}
			if (matrix[i][j - k] == '1'){
				col++;
			}
			//找到最大边长
			if (matrix[i - k][j] == '0' || matrix[i][j - k] == '0'){
				break;
			}
		}
		x = min(col, row) + 1;
		return x;

	}
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		//保存以[i,j]为右下角最大正方形面积
		vector<vector<int>> dp(row, vector<int>(col, 0));
		int ans = 0;
		//初始化，只有一个值，就是当前值
		for (int i = 0; i<row; i++){
			dp[i][0] = matrix[i][0] - '0';
			ans = max(ans, dp[i][0]);
		}
		for (int j = 0; j<col; j++){
			dp[0][j] = matrix[0][j] - '0';
			ans = max(ans, dp[0][j]);
		}

		int m = 0;
		int len = 0;
		for (int i = 1; i<row; i++){
			for (int j = 1; j<col; j++){
				m = dp[i - 1][j - 1];
				//求边长的最大范围
				len = sqrt(m);
				//由左上角构成正方形，并且当前值不为0
				//judge求出最长边长
				if (m != 0 && matrix[i][j] == '1'){
					//求最大边长
					int x = Judge(matrix, i, j, len);
					dp[i][j] = x*x;
				}
				else{
					dp[i][j] = matrix[i][j] - '0';
				}
				//得到最大值
				if (ans < dp[i][j]){
					ans = dp[i][j];
				}

			}

		}
		return ans;

	}
};



优解：
状态定义：[i，j]最大正方形边长。 也表示以(i, j) 为右下角的正方形的数目为 x（即边长为 1, 2, ..., x 的正方形各一个）。

转移方程：
最大正方形，只会与左上角，上一行的当前列，上一列的当前行，的最大正方形有关。
就是求得最大正方形全1的边长



取最小值，肯定可以构成正方形

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		//最大正方形边长/[0，i]边长[0~i]的正方形个数
		vector<vector<int>> dp(row, vector<int>(col, 0));
		int maxside = 0;
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				//第一行第一列。防止越界
				if (i == 0 || j == 0){
					dp[i][j] = matrix[i][j] - '0';
				}
				//当前值为0，不能构成正方形，边长为0
				else if (matrix[i][j] == '0'){
					dp[i][j] = 0;
				}
				else{
					//左上角，上一行的当前列，上一列的当前行
					//取最小值，肯定可以构成正方形
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;//求得最大边长
				}
				maxside = max(maxside, dp[i][j]);
			}
		}
		return maxside*maxside;

	}
};

