class Solution {
public:
	// bool isPal(string& s,int left,int right){
	//     while(left<right){
	//         if(s[left++]!=s[right--]){
	//             return false;
	//         }
	//     }
	//     return true;
	// }
	//�жϻ��Ĵ��ö��棬
	vector<vector<bool>> isPal(string& s){
		int len = s.size();
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		for (int i = len - 1; i >= 0; i--){
			for (int j = i; j<len; j++){
				if (j == i){
					dp[i][j] = true;
				}
				else if (j == i + 1){
					dp[i][j] = (s[j] == s[i]);
				}
				else{
					dp[i][j] = (s[j] == s[i]) && dp[i + 1][j - 1];
				}

			}
		}
		return dp;
	}
	//�Ż��ռ任ȡʱ��
	int countSubstrings(string s) {
		int len = s.size();
		int res = len;
		vector<vector<bool>> dp = isPal(s);
		for (int i = 1; i<len; i++){
			for (int j = i - 1; j >= 0; j--){
				//�ǻ��Ĵ������Ĵ�������1
				if (dp[j][i]){
					res++;
				}
			}
		}
		return res;

	}
};