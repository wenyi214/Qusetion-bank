class Solution {
public:
	int knapsack(int V, int n, vector<vector<int> >& vw) {
		// write code here
		//初始化，dp[0][j]=0,dp[i][0]=0
		vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
		//先遍历物品
		for (int i = 1; i <= n; i++){
			//再遍历背包容量
			for (int j = 1; j <= V; j++){
				//放得下
				if (j >= vw[i - 1][0])
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
				//放不下
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[n][V];
	}
};

//优化
class Solution {
public:
	int knapsack(int V, int n, vector<vector<int> >& vw) {
		//初始化，没放物品，初始化为0
		vector<int> dp(V + 1, 0);
		//物品
		for (int i = 1; i <= n; i++){
			//背包容量。倒序遍历
			for (int j = V; j>0; j--){
				//放得下
				if (j >= vw[i - 1][0]){
					dp[j] = max(dp[j], dp[j - vw[i - 1][0]] + vw[i - 1][1]);
				}

				//放不下就是原来的值
			}
		}
		return dp[V];
	}
};