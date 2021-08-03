//���ۣ�377.����ܺ� �� ��ȫ��������
//�����ѭ��Ϊ��Ʒ�����ѭ��Ϊ��������ʱ�������������ķ�������
//�����ѭ��Ϊ�������������ѭ��Ϊ��Ʒʱ��������������ķ�������


class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		//�����������ȫ��������
		//����Ҫ�ı����˳�����������������������ϲŽ����е����з�������
		for (int i = 1; i <= target; i++){
			for (int j = 1; j <= len; j++){
				//��ֹdp[i]Խ��int
				if (i >= nums[j - 1] && dp[i] < INT_MAX - dp[i - nums[j - 1]]){
					dp[i] += dp[i - nums[j - 1]];
				}
			}
		}
		return dp[target];


	}
};