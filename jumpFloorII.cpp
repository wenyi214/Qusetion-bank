class Solution {
public:
	int jumpFloorII(int number) {

		vector<int> dp(number + 1, 0);
		//初始化
		dp[0] = 0;
		dp[1] = 1;
		//转移方程
		for (int i = 2; i <= number; i++){
			dp[i] = 2 * dp[i - 1];
		}
		return dp[number];

	}
};