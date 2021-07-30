//力扣 1049 最后一块石头的重量 II
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {

		int len = stones.size();
		int sum = 0;
		//求和
		for (int i = 0; i<len; i++){
			sum += stones[i];
		}
		//背包容量
		int v = sum / 2;

		vector<int> dp(v + 1, 0);
		//最后求出来的值肯定小于等于v
		for (int i = 1; i <= stones.size(); i++){
			for (int j = v; j>0; j--){
				if (j >= stones[i - 1]){
					dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
				}
			}
		}
		//sum-dp[v]为剩下的，减dp[v]就是最小差值
		return sum - dp[v] - dp[v];

	}
};