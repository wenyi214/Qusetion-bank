//力扣 474 一和零
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		//两个维度的01背包问题。背包包含两个容量0的容量。1的容量性质

		int len = strs.size();
		//初始化，不选strs里的数，里面的子集元素个数为0
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int s = 0; s<len; s++){
			int sumzero = 0;
			int sumone = 0;
			int x = strs[s].size();
			//求出字符串中0和1的个数
			for (int j = 0; j<x; j++){
				if (strs[s][j] == '0'){
					sumzero++;
				}
				else{
					sumone++;
				}
			}
			//问的是子集个数，每个数就代表一个，所以价值为1
			//价值为1 ，物品容量为0和1的个数
			//要等于0，01个数可能为0
			for (int i = m; i >= 0; i--){
				for (int j = n; j >= 0; j--){
					if (i >= sumzero&&j >= sumone){
						dp[i][j] = max(dp[i][j], dp[i - sumzero][j - sumone] + 1);
					}
				}
			}
		}
		return dp[m][n];


	}
};