class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		//̨����
		int n = cost.size();
		//������
		vector<int> dp(n + 1, 0);
		//��ʼ��
		dp[0] = 0;
		dp[1] = 0;
		//ת�Ʒ���
		for (int i = 2; i <= n; i++){
			dp[i] = min((dp[i - 2] + cost[i - 2]), (dp[i - 1] + cost[i - 1]));
		}
		return dp[n];

		//�Ż�
		int n = cost.size();
		int first = 0;
		int second = 0;
		int result = 0;
		for (int i = 2; i <= n; i++){
			result = min(first + cost[i - 2], second + cost[i - 1]);
			first = second;
			second = result;
		}
		return result;
	}
};