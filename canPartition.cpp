class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int len = nums.size();
		int sum = 0;
		//�󼯺��ܺ�
		for (int i = 0; i<len; i++){
			sum += nums[i];
		}
		//������������϶��Ҳ�����ȵ�
		if (sum % 2){
			return false;
		}

		int v = sum / 2;
		//��ʼ��
		vector<int> dp(v + 1, 0);
		//��Ʒ
		for (int i = 1; i <= len; i++){
			//��������
			for (int j = v; j>0; j--){
				if (j >= nums[i - 1]){
					dp[j] = max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
				}
			}
		}
		return dp[v] == v;
	}
};