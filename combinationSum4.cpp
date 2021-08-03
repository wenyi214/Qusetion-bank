//力扣：377.组合总和 Ⅳ 完全背包问题
//当外层循环为物品，里层循环为背包容量时，求的是组合数的方法数。
//当外层循环为背包容量，里层循环为物品时，求的是排列数的方法数。


class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		//排列问题的完全背包问题
		//这里要改变遍历顺序，外层遍历背包容量，方法上才将排列的所有方法加上
		for (int i = 1; i <= target; i++){
			for (int j = 1; j <= len; j++){
				//防止dp[i]越界int
				if (i >= nums[j - 1] && dp[i] < INT_MAX - dp[i - nums[j - 1]]){
					dp[i] += dp[i - nums[j - 1]];
				}
			}
		}
		return dp[target];


	}
};