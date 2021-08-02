//���ۣ�518.��Ǯ�һ� II
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int len = coins.size();
		vector<int> dp(amount + 1, 0);
		//��ʼ��
		dp[0] = 1;

		for (int i = 1; i <= len; i++){
			//��ȫ�������������
			for (int j = 1; j <= amount; j++){
				//�󷽷���
				if (j >= coins[i - 1]){
					dp[j] += dp[j - coins[i - 1]];
				}
			}
		}
		return dp[amount];

	}
};