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
//dp[i][5]：第i天第三次买入最大价值
//
//dp[i][6]：第i天第三次卖出最大价值
//
//.......
//
//dp[i][2 * k - 1]：第i天第k次买入最大价值
//
//dp[i][2 * k]：第i天第k次卖出最大价值
//
//列为奇数下标买入，列为偶数小标卖出。
//
//dp横坐标为天数，纵坐标为状态
//
//转移方程：
//
//dp[i][0]不交易始终为0
//
//每一次的买入都是上一次（不是天）的利润减去这天股票篇的价格与前一天的这一次买入价格最大值
//
//dp[i][j] = max(dp[i][j - 1] - prices[i], dp[i - 1][j])
//
//每一次卖出都是当天剩余的钱加上当天股票价值与上一天这一次的利润的最大值。
//
//dp[i][j + 1] = max(dp[i][j] + prices[i]，dp[i - 1][j + 1])
//
//初始化：
//
//第一天所有的买入都是 - prices[0]，数组上是下标为奇数的，值为 - prices[0]。
//
//返回值：
//
//dp[prices.size()][2 * k], 最后不持有股票的最大价值。
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int len = prices.size();
		if (len == 0){
			return 0;
		}
		vector<vector<int>> dp(len + 1, vector<int>(2 * k + 1, 0));
		//初始化，奇数下标，j从1开始，更新j，j+=2
		for (int j = 1; j<2 * k; j += 2){
			dp[1][j] = -prices[0];
		}
		//递推公式
		for (int i = 2; i <= len; i++){
			//更新j，j+=2,不是j=2*j+1，少了5
			for (int j = 1; j<2 * k; j += 2){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1] - prices[i - 1]);
				dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i][j] + prices[i - 1]);
			}
		}
		return dp[len][2 * k];

	}
};