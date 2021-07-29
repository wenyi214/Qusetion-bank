//力扣 494 目标和
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		int len = nums.size();

		for (int i = 0; i<len; i++){
			sum += nums[i];
		}

		//为奇数，得不到
		if ((sum + target) % 2)
			return 0;
		//要找到和的数
		int m = (sum + target) / 2;
		//要求的数都大于总和了 得不到
		if (m>sum)
			return 0;
		vector<int> dp(m + 1, 0);
		//初始化，值为0，不选数
		dp[0] = 1;
		for (int i = 1; i <= len; i++){
			//要等于0，有值等于0的情况，体积等于0的情况
			for (int j = m; j >= 0; j--){
				if (j >= nums[i - 1]){
					//等于之前就可以使值等于j的方法数，加，现在加一个数可以使值等于j的方法数。
					dp[j] += dp[j - nums[i - 1]];
				}
			}
		}
		return dp[m];

	}
};