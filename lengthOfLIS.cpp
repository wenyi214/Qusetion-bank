//状态定义：
//
//必须有第i个数(包括第i个)的最长递增子序列，dp[i]。
//
//转移方程：
//
//如果第i个数大于第j(0 <= j<i)个数，说明这个时候的递增子序列为dp[j] + 1。但是要求出最长的递增子序列，所以要将nums[i]与i之前的所有数比较。
//
//即if(nums[i]>nums[j]) dp[i] = max(dp[i], dp[j] + 1)。这里max里的dp[i]只是为了求出最大值。
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
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		//初始化
		vector<int> dp(len, 1);
		//转移方程
		for (int i = 1; i<len; i++){
			for (int j = 0; j<i; j++){
				if (nums[i]>nums[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		//找返回值
		int m = 0;
		for (auto n : dp){
			m = max(n, m);
		}
		return m;

	}
};