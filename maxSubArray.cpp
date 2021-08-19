
//̰��
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = nums[0];
		int sum = 0;
		int len = nums.size();
		for (int i = 0; i<len; i++){
			sum += nums[i];
			if (max<sum){
				max = sum;
			}
			if (sum<0){
				sum = 0;
			}
		}
		return max;

	}
};
//����
//״̬���壺
//
//numsǰi - 1����(�������nums[i - 1])����������к͡��������dp�������������ֵ��
//
//ת�Ʒ��̣�
//
//״̬�������ֽ���õ���
//
//dp[i - 1] + nums[i - 1]��Ҫ���������Ա������nums[i - 1]������nums[i - 1]�������к͡�
//
//nums[i - 1], ��ͷ��ʼ���㡣
//
//��ʼ����
//
//dp[0] = 0��û������
//
//����ֵ��
//
//�������ֵ��
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		//��ʼ��
		vector<int> dp(len + 1, 0);
		//����������nums[0]��ʼ������Ϊ��
		int result = nums[0];
		for (int i = 1; i <= len; i++){
			//ת�Ʒ��̣���ΪҪ������dp[i-1]+nums[i-1]
			//��ͷ��ʼ���㣬nums[i-1]
			dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
			result = max(result, dp[i]);

		}
		return result;

	}
};