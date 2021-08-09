//状态定义 ：
//
//可以用一个二维数组保持结果。二维数组有i行，两列。第一列代表持有股票的最大价值。第二列代表不持有股票的最大价值。
//
//dp[i][0]  第i天持有股票的最大价值（最小成本）
//
//dp[i][1] 第i天不持有股票的最大价值（最大收益）
//
//转移方程：
//
//前一天不持有股票的价值与当天交易的价值即：dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i - 1] - fee);

//初始化：
//
//第一天持有股票，只能是买入股票，因为没有之前的对比。dp[1][0] = -price[0]
//
//第一天不持有股票的最大价值，只能是将持有股票的卖出。dp[1][1] = dp[1][0] + price[0] = 0
//
//返回值：
//
//最后一天不持有股票的最大价值dp[price.size()][1]。
class Solution {
public:
	//状态和第二题一样
	int maxProfit(vector<int>& prices, int fee) {
		int len = prices.size();
		vector<vector<int>> dp(len + 1, vector<int>(2, 0));
		dp[1][0] = -prices[0];
		dp[1][1] = 0;

		for (int i = 2; i <= len; i++){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
			dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i - 1] - fee);
		}
		return dp[len][1];

	}
};