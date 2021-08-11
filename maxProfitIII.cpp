//状态定义：
//
//我们可以定义5个状态：
//
//dp[i][0]：第i天不交易最大价值
//
//dp[i][1]：第i天第一次买入最大价值
//
//dp[i][2]：第i天第一次卖出最大价值
//
//dp[i][3]：第i天第二次买入最大价值
//
//dp[i][4]：第i天第二次卖出最大价值
//
//dp横坐标为天数，纵坐标为5种状态
//
//转移方程：
//
//有了上面两题，相信大家很容易得出转移方程：不如自己写一下
//
//dp[i][0]不交易始终为0
//
//dp[i][1]和dp[i][2]就像第一题一样。
//
//dp[i][1]第一次买入，当前买入和之前买入的最大值。dp[i][0] = max(dp[i][0] - prices[i]，dp[i - 1][1])。
//
//dp[i][2]第一次卖出，当前卖出价值和之前价值最大值。dp[i][1] = max(dp[i][1] + prices[i]，dp[i - 1][2])。
//
//dp[i][3]和dp[i][4]就和第二题一样
//
//dp[i][3]第二次买入，当前买入(已有利润)和之前买入的最大值。dp[i][0] = max(dp[i - 1][2] - prices[i]，dp[i - 1][3])。
//
//dp[i][4]第二次卖出，当前卖出价值和之前价值最大值。dp[i][1] = max(dp[i][3] + prices[i]，dp[i - 1][4])。
//
//初始化：
//
//第一天你不操作：dp[1][0] = 0
//
//第一天你买入：dp[1][1] = -prices[i - 1]。
//
//第一天你卖出：dp[1][2] = dp[1][1] + prices[i - 1] = 0
//
//第二天你买入：dp[1][3] = dp[1][2] - prices[i - 1]
//
//第二天你卖出：dp[1][4] = dp[1][3] + prices[i - 1] = 0
//
//返回值：
//
//dp[prices.size()][4], 最后不持有股票的最大价值。
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> dp(len + 1, vector<int>(5, 0));
		//初始化
		dp[1][0] = 0;
		dp[1][1] = -prices[0];
		dp[1][2] = 0;
		dp[1][3] = -prices[0];
		dp[1][4] = 0;
		//转移方程
		for (int i = 2; i <= len; i++){
			dp[i][1] = max(-prices[i - 1], dp[i - 1][1]);
			dp[i][2] = max(dp[i - 1][2], dp[i][1] + prices[i - 1]);
			dp[i][3] = max(dp[i - 1][2] - prices[i - 1], dp[i - 1][3]);
			dp[i][4] = max(dp[i][3] + prices[i - 1], dp[i - 1][4]);
		}
		return dp[len][4];


	}
};