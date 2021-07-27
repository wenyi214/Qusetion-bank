class Solution {
public:
	int integerBreak(int n) {
		//初始化。dp[0]=0,dp[1]=0
		vector<int> dp(n + 1, 0);
		//一般都是从初始化后一个值开始
		for (int i = 2; i <= n; i++){
			int Max = 0;
			//计算到一半，后面都是重复的计算
			for (int j = 1; j <= i - j; j++){
				//转移方程
				Max = max(Max, max(j*(i - j), j*dp[i - j]));
			}
			dp[i] = Max;
		}
		return dp[n];


	}
};