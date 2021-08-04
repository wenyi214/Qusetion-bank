//���ۣ�279. ��ȫƽ����
class Solution {
public:
	int numSquares(int n) {
		vector<int> nums;
		int len = sqrt(n);
		//����ȫƽ����
		for (int i = 1; i <= len; i++){
			nums.push_back(i*i);
		}

		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= len; i++){
			for (int j = nums[i - 1]; j <= n; j++){
				if (dp[j - nums[i - 1]]<INT_MAX){
					dp[j] = min(dp[j], dp[j - nums[i - 1]] + 1);
				}

			}
		}
		return dp[n];

	}
};