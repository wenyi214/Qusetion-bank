//状态定义：
//
//必须有第i个数(包括第i个)的最长递增子序列，dp[i]。
//
//状态转移方程：
//
//因为需要连续，所以不需要加一个循环与前面每一个都要比较。连续只需要与前一个比较就好了。if(nums[i]>nums[i - 1])  dp[i] = max(dp[i], dp[i - 1] + 1)
//
//初始化：
//
//每一个数都可以看作一个递增子序列，dp[i] = 1
//
//返回值：
//
//在dp数组中找到最大值返回。

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		//初始化
		vector<int> dp(len, 1);
		//转移方程
		for (int i = 1; i<len; i++){
			if (nums[i]>nums[i - 1]){
				dp[i] = dp[i - 1] + 1;
			}
		}
		//找返回值
		int m = 0;
		for (auto n : dp){
			m = max(m, n);
		}
		return m;

	}
};