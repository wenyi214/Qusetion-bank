//״̬���壺
//
//����text1��i - 1��β������text2��j - 1��β�Ĺ�������������������С�(�����������в��������������)��
//
//ת�Ʒ��̣�
//
//��Ӱ
//
//��text1[i - 1] == text2[j - 1]ʱ��dp[i][j] = dp[i - 1][j - 1] + 1��text1ǰi - 2����text2ǰj - 2������������и��������ϼ�1��
//
//��text1[i - 1] != text2[j - 1]ʱ�������������test1ǰi - 2������test2ǰj - 1���������������dp[i - 1][j]��test1ǰi - 1������test2ǰj - 2���������������dp[i][j - 1]�������е����ֵ��
//
//max(dp[i][j - 1], dp[i - 1][j])��
//
//��ʼ����
//
//dp[i][0] = 0��text1����û��Ԫ��
//
//dp[0][j] = 0��text2����û��Ԫ��
//
//����ֵ��
//
//����Ԫ����ֵ����


class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.size();
		int len2 = text2.size();
		//��ʼ��
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		int result = 0;
		//ת�Ʒ���
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				//��Ӱ
				if (text1[i - 1] == text2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
				//�õ�����ֵ
				result = max(result, dp[i][j]);
			}
		}
		return result;

	}
};