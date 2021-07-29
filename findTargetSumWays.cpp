//���� 494 Ŀ���
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		int len = nums.size();

		for (int i = 0; i<len; i++){
			sum += nums[i];
		}

		//Ϊ�������ò���
		if ((sum + target) % 2)
			return 0;
		//Ҫ�ҵ��͵���
		int m = (sum + target) / 2;
		//Ҫ������������ܺ��� �ò���
		if (m>sum)
			return 0;
		vector<int> dp(m + 1, 0);
		//��ʼ����ֵΪ0����ѡ��
		dp[0] = 1;
		for (int i = 1; i <= len; i++){
			//Ҫ����0����ֵ����0��������������0�����
			for (int j = m; j >= 0; j--){
				if (j >= nums[i - 1]){
					//����֮ǰ�Ϳ���ʹֵ����j�ķ��������ӣ����ڼ�һ��������ʹֵ����j�ķ�������
					dp[j] += dp[j - nums[i - 1]];
				}
			}
		}
		return dp[m];

	}
};