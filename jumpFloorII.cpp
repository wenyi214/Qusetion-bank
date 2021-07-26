class Solution {
public:
	int jumpFloorII(int number) {

		vector<int> dp(number + 1, 0);
		//��ʼ��
		dp[0] = 0;
		dp[1] = 1;
		//ת�Ʒ���
		for (int i = 2; i <= number; i++){
			dp[i] = 2 * dp[i - 1];
		}
		return dp[number];

	}
};