//״̬���壺
//
//�����е�i����(������i��)������������У�dp[i]��
//
//ת�Ʒ��̣�
//
//�����i�������ڵ�j(0 <= j<i)������˵�����ʱ��ĵ���������Ϊdp[j] + 1������Ҫ�����ĵ��������У�����Ҫ��nums[i]��i֮ǰ���������Ƚϡ�
//
//��if(nums[i]>nums[j]) dp[i] = max(dp[i], dp[j] + 1)������max���dp[i]ֻ��Ϊ��������ֵ��
//
//��ʼ����
//
//ÿһ���������Կ���һ�����������У�dp[i] = 1
//
//����ֵ��
//
//��dp�������ҵ����ֵ���ء�
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		//��ʼ��
		vector<int> dp(len, 1);
		//ת�Ʒ���
		for (int i = 1; i<len; i++){
			for (int j = 0; j<i; j++){
				if (nums[i]>nums[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		//�ҷ���ֵ
		int m = 0;
		for (auto n : dp){
			m = max(n, m);
		}
		return m;

	}
};