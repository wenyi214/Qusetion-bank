//���� 474 һ����
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		//����ά�ȵ�01�������⡣����������������0��������1����������

		int len = strs.size();
		//��ʼ������ѡstrs�������������Ӽ�Ԫ�ظ���Ϊ0
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int s = 0; s<len; s++){
			int sumzero = 0;
			int sumone = 0;
			int x = strs[s].size();
			//����ַ�����0��1�ĸ���
			for (int j = 0; j<x; j++){
				if (strs[s][j] == '0'){
					sumzero++;
				}
				else{
					sumone++;
				}
			}
			//�ʵ����Ӽ�������ÿ�����ʹ���һ�������Լ�ֵΪ1
			//��ֵΪ1 ����Ʒ����Ϊ0��1�ĸ���
			//Ҫ����0��01��������Ϊ0
			for (int i = m; i >= 0; i--){
				for (int j = n; j >= 0; j--){
					if (i >= sumzero&&j >= sumone){
						dp[i][j] = max(dp[i][j], dp[i - sumzero][j - sumone] + 1);
					}
				}
			}
		}
		return dp[m][n];


	}
};