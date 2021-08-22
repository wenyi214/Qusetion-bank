//״̬���壺
//
//ʹ��word1[i - 1]����word2[j - 1]����С������
//
//ת�Ʒ��̣�
//
//���������
//
//��word1[i - 1] == word[j - 1]ʱ������ɾ���ַ���������Ҫ������dp[i][j] = dp[i - 1][j - 1]��
//
//��word1[i - 1] != word[j - 1]ʱ����Ҫɾ���ַ������������
//
//1.ɾ��word1�ĵ�i - 1�ַ���dp[i - 1][j] + 1����1����Ϊ��ɾ������������1��
//
//2.ɾ��word2�ĵ�j - 1�ַ���dp[i][j - ] + 1
//
//3.ɾ��word1�ĵ�i - 1�ַ���ɾ��word2�ĵ�j - 1�ַ���dp[i - 1][j - 1] + 2��������ɾ��������
//
//��С����������dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 2)
//
//��ʼ����
//
//dp[0][j] = j��word1û���ַ�����Ҫ��word2�ַ�ȫ��ɾ����
//
//dp[i][0] = i��word2û���ַ�����Ҫ��word1�ַ�ȫ��ɾ����
//
//����ֵ��
//
//dp[word1.size()][word2.size()]��
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		//��ʼ��
		for (int i = 1; i <= len1; i++){
			dp[i][0] = i;
		}
		for (int j = 0; j <= len2; j++){
			dp[0][j] = j;
		}
		//ת�Ʒ���
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (word1[i - 1] == word2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + 2);
				}
			}
		}
		return dp[len1][len2];

	}
};