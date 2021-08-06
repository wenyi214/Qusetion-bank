//状态定义：前i个中最大价值
//转移方程：
//dp[i]最大值由两种情况
//取nums[i], 由于相邻的会报警，最大值为dp[i - 2] + nums[i]
//不取nums[i], dp[i]的最大值就是dp[i - 1]
//dp[i]最大值为max(dp[i - 1], dp[i - 2] + nums[i])
//
//初始化：
//dp[0] = 0  dp[1] = nums[0] dp[2] = max(nums[1]，nums[0])
//返回值为  dp[nums.size()]
	class Solution {
	public:
		int rob(vector<int>& nums) {
			int len = nums.size();
			if (len == 0){
				return 0;
			}
			if (len == 1){
				return nums[0];
			}
			vector<int> dp(len + 1, 0);
			//初始化
			dp[1] = nums[0];
			dp[2] = max(nums[0], nums[1]);
			//转移方程
			for (int i = 2; i <= len; i++){
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
			}
			return dp[len];

		}
	};