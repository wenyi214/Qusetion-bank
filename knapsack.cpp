class Solution {
public:
	int knapsack(int V, int n, vector<vector<int> >& vw) {
		// write code here
		//��ʼ����dp[0][j]=0,dp[i][0]=0
		vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
		//�ȱ�����Ʒ
		for (int i = 1; i <= n; i++){
			//�ٱ�����������
			for (int j = 1; j <= V; j++){
				//�ŵ���
				if (j >= vw[i - 1][0])
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
				//�Ų���
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[n][V];
	}
};

//�Ż�
class Solution {
public:
	int knapsack(int V, int n, vector<vector<int> >& vw) {
		//��ʼ����û����Ʒ����ʼ��Ϊ0
		vector<int> dp(V + 1, 0);
		//��Ʒ
		for (int i = 1; i <= n; i++){
			//�����������������
			for (int j = V; j>0; j--){
				//�ŵ���
				if (j >= vw[i - 1][0]){
					dp[j] = max(dp[j], dp[j - vw[i - 1][0]] + vw[i - 1][1]);
				}

				//�Ų��¾���ԭ����ֵ
			}
		}
		return dp[V];
	}
};