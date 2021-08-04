//力扣 322. 零钱兑换
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int len = coins.size();
		//初始化出0外，其它都初始化为INT_MAX，
		//为什么初始化为INT_MAX,求的是最小值，
		vector<int> dp(amount + 1, INT_MAX);
		//为什么初始化为0，每个值都是从容量0开始往上加的
		dp[0] = 0;

		for (int i = 1; i <= len; i++){
			for (int j = 1; j <= amount; j++){
				//防止越界
				if (j >= coins[i - 1] && dp[j - coins[i - 1]]<INT_MAX){
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
					//flag=1;

				}
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];


	}
};