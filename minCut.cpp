//132. 分割回文串 II
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

	vector<vector<int>> isPal(string& s){
		int len = s.size();
		//初始化
		vector<vector<int>> dp(len, vector<int>(len, false));
		//从后往前
		//从那个开始[i,j],倒三角
		for (int i = len - 1; i >= 0; i--){

			for (int j = i; j<len; j++){
				if (i == j){
					dp[i][j] = true;
				}
				else if (j == i + 1){
					dp[i][j] = (s[i] == s[j]);
				}
				else{
					dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
				}

			}
		}
		return dp;

	}
	int minCut(string s) {
		vector<int> dp;
		vector<vector<int>> res = isPal(s);
		int len = s.size();
		//初始化
		for (int i = 0; i <= len; i++){
			dp.push_back(i - 1);
		}

		for (int i = 1; i <= len; i++){

			for (int j = i - 1; j >= 0; j--){
				//字符缩影，因为加了辅助位，i=1时就是字符1，但是字符保存再数组了，缩影从0开始
				if (res[j][i - 1]){
					//要得到最小值，所以要dp[i]也要比
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[len];


	}
};