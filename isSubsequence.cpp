//״̬���壺
//
//���±�i - 1��β���ַ���s�����±�j - 1��β���ַ���j - 1����ͬԪ�صĸ�����dp[i][j]��Ϊʲô��i - 1��j - 1���ַ�����Ӱ��
//
//ת�Ʒ��̣�
//
//���s[i - 1] == t[j - 1]��dp[i][j] = dp[i - 1][j - 1] + 1������һ����ͬԪ��s[i - 1]��t[j - 1]��
//
//���s[i - 1] != t[j - 1]��Ҫ��t[j - 1]ɾ�����Ƚ�s[i - 1]��t[j - 2]����dp[i][j] = dp[i][j - 1]��
//
//��ʼ����
//
//dp[i][0] = 0��tû��Ԫ�أ���ͬ������Ϊ0
//
//dp[0][j] = 0��sû��Ԫ�أ���ͬ������Ϊ0
//
//����ֵ��
//
//dp[s.size()][t.size()] == s.size()�����Ԫ�ظ�������s��Ԫ�ظ�����˵��s��Ԫ����t�


class Solution {
public:
	bool isSubsequence(string s, string t) {
		int len1 = s.size();
		int len2 = t.size();
		//��ʼ��
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		//ת�Ʒ���
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				if (s[i - 1] == t[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = dp[i][j - 1];
				}

			}

		}
		return dp[len1][len2] == len1;

	}
};