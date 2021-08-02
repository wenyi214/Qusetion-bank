//力扣：518.零钱兑换 II
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int len = coins.size();
		vector<int> dp(amount + 1, 0);
		//初始化
		dp[0] = 1;

		for (int i = 1; i <= len; i++){
			//完全背包，正序遍历
			for (int j = 1; j <= amount; j++){
				//求方法数
				if (j >= coins[i - 1]){
					dp[j] += dp[j - coins[i - 1]];
				}
			}
		}
		return dp[amount];

	}
};