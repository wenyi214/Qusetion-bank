//��̬�滮��
//״̬���壺
//�ߵ�i��j��������ֵdp[i][j]
//ת�Ʒ��̣�
//����ֻ�����Һ������ߣ��Ӵ��ֵ���ڸ�λ�ã����������ֵ���ұ�����ֵ�����ֵ�����ϵ�ǰλ�õļ�ֵ
//dp[i][j] = max(dp[i - 1][j]��dp[i][j - 1]) + grids[i][j]
//��ʼ����
//��һ��ֻ��һֱ������
//��һ��ֻ��һֱ������
//for (int i = 1; i<len1; i++){
//	dp[i][0] = dp[i - 1][0] + grid[i][0];
//}
//for (int j = 1; j<len2; j++){
//	dp[0][j] = dp[0][j - 1] + grid[0][j];
//}
//����ֵ
//dp[grid.size][grid[0].size]
	class Solution {
	public:
		int maxValue(vector<vector<int>>& grid) {
			int len1 = grid.size();
			int len2 = grid[0].size();

			vector<vector<int>> dp(len1, vector<int>(len2, 0));
			dp[0][0] = grid[0][0];
			//��ʼ��
			for (int i = 1; i<len1; i++){
				dp[i][0] = dp[i - 1][0] + grid[i][0];
			}
			for (int j = 1; j<len2; j++){
				dp[0][j] = dp[0][j - 1] + grid[0][j];
			}


			for (int i = 1; i<len1; i++){
				for (int j = 1; j<len2; j++){
					//ת�Ʒ���
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}

			return dp[len1 - 1][len2 - 1];

		}
	};