//���� 322. ��Ǯ�һ�
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int len = coins.size();
		//��ʼ����0�⣬��������ʼ��ΪINT_MAX��
		//Ϊʲô��ʼ��ΪINT_MAX,�������Сֵ��
		vector<int> dp(amount + 1, INT_MAX);
		//Ϊʲô��ʼ��Ϊ0��ÿ��ֵ���Ǵ�����0��ʼ���ϼӵ�
		dp[0] = 0;

		for (int i = 1; i <= len; i++){
			for (int j = 1; j <= amount; j++){
				//��ֹԽ��
				if (j >= coins[i - 1] && dp[j - coins[i - 1]]<INT_MAX){
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
					//flag=1;

				}
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];


	}
};