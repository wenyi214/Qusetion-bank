class Solution {

public:
	string longestPalindrome(string s) {
		int len = s.size();
		int x = 0;
		vector<vector<bool>> dp(len + 1, vector<bool>(len + 1, false));
		int max = 0;//��¼����
		//�����Ƿ����Ӵ�
		//��[i,j]
		for (int i = len; i >= 1; i--){
			for (int j = i; j <= len; j++){
				if (i == j){
					dp[i][j] = true;
				}
				else if (i + 1 == j){
					dp[i][j] = s[i - 1] == s[j - 1];
				}
				else{
					dp[i][j] = ((s[i - 1] == s[j - 1]) && dp[i + 1][j - 1]);
				}
				//�ҳ�����Ӵ�����¼�±꣬�ͳ���
				if (dp[i][j] == true && max < j - i + 1){
					max = j - i + 1;
					x = i - 1;
				}

			}
		}

		return s.substr(x, max);
	}
};