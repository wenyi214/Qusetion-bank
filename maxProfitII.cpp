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
//持有股票的最大价值变了：由于可以多次买入卖出，可能之前手里的价值不为0了，可能已经有收益。
//所以当天买入股票时的价值不是 - price[i]，而是dp[i][1] - price[i]，收益减去买入股票的前。
//但是持有股票的最大价值也鄙视一定当天买入，也是要在收益最大时，在价值最低点买入。所以持有股票的最大价值为 dp[i][0] = max(dp[i][0] - prices[i]，dp[i - 1][0])。

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
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> dp(len + 1, vector<int>(2, 0));
		//初始化
		dp[1][0] = -prices[0];
		dp[1][1] = 0;
		//转移方程
		for (int i = 2; i <= len; i++){
			dp[i][0] = max(dp[i - 1][1] - prices[i - 1], dp[i - 1][0]);
			dp[i][1] = max(dp[i][0] + prices[i - 1], dp[i - 1][1]);
		}
		return dp[len][1];

	}
};

//以天为单位，将所有的正利润加起来。
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		int len = prices.size();
		for (int i = 1; i<len; i++){
			res += max(prices[i] - prices[i - 1], 0);
		}
		return res;

	}
};


