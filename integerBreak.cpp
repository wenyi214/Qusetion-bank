class Solution {
public:
	int integerBreak(int n) {
		//��ʼ����dp[0]=0,dp[1]=0
		vector<int> dp(n + 1, 0);
		//һ�㶼�Ǵӳ�ʼ����һ��ֵ��ʼ
		for (int i = 2; i <= n; i++){
			int Max = 0;
			//���㵽һ�룬���涼���ظ��ļ���
			for (int j = 1; j <= i - j; j++){
				//ת�Ʒ���
				Max = max(Max, max(j*(i - j), j*dp[i - j]));
			}
			dp[i] = Max;
		}
		return dp[n];


	}
};