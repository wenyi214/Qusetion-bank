//״̬���壺ǰi��������ֵ
//ת�Ʒ��̣�
//dp[i]���ֵ���������
//ȡnums[i], �������ڵĻᱨ�������ֵΪdp[i - 2] + nums[i]
//��ȡnums[i], dp[i]�����ֵ����dp[i - 1]
//dp[i]���ֵΪmax(dp[i - 1], dp[i - 2] + nums[i])
//
//��ʼ����
//dp[0] = 0  dp[1] = nums[0] dp[2] = max(nums[1]��nums[0])
//����ֵΪ  dp[nums.size()]
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
			//��ʼ��
			dp[1] = nums[0];
			dp[2] = max(nums[0], nums[1]);
			//ת�Ʒ���
			for (int i = 2; i <= len; i++){
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
			}
			return dp[len];

		}
	};