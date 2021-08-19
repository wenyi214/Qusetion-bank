
//贪心
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = nums[0];
		int sum = 0;
		int len = nums.size();
		for (int i = 0; i<len; i++){
			sum += nums[i];
			if (max<sum){
				max = sum;
			}
			if (sum<0){
				sum = 0;
			}
		}
		return max;

	}
};
//动规
//状态定义：
//
//nums前i - 1个数(必须包括nums[i - 1])中最大子序列和。这个不是dp数组个数中最大的值。
//
//转移方程：
//
//状态可由两种结果得到：
//
//dp[i - 1] + nums[i - 1]。要连续，所以必须加上nums[i - 1]，加上nums[i - 1]的子序列和。
//
//nums[i - 1], 从头开始计算。
//
//初始化：
//
//dp[0] = 0，没有数。
//
//返回值：
//
//里面最大值。
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		//初始化
		vector<int> dp(len + 1, 0);
		//保存结果，从nums[0]开始，可能为负
		int result = nums[0];
		for (int i = 1; i <= len; i++){
			//转移方程，因为要连续，dp[i-1]+nums[i-1]
			//从头开始计算，nums[i-1]
			dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
			result = max(result, dp[i]);

		}
		return result;

	}
};