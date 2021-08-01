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
	//判断回文串用动规，
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
	//优化空间换取时间
	int countSubstrings(string s) {
		int len = s.size();
		int res = len;
		vector<vector<bool>> dp = isPal(s);
		for (int i = 1; i<len; i++){
			for (int j = i - 1; j >= 0; j--){
				//是回文串，回文串个数加1
				if (dp[j][i]){
					res++;
				}
			}
		}
		return res;

	}
};