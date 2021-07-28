class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int len = nums.size();
		int sum = 0;
		//求集合总和
		for (int i = 0; i<len; i++){
			sum += nums[i];
		}
		//如果是奇数，肯定找不到相等的
		if (sum % 2){
			return false;
		}

		int v = sum / 2;
		//初始化
		vector<int> dp(v + 1, 0);
		//物品
		for (int i = 1; i <= len; i++){
			//背包容量
			for (int j = v; j>0; j--){
				if (j >= nums[i - 1]){
					dp[j] = max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
				}
			}
		}
		return dp[v] == v;
	}
};