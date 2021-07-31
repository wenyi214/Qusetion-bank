//132. �ָ���Ĵ� II
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
		//��ʼ��
		vector<vector<int>> dp(len, vector<int>(len, false));
		//�Ӻ���ǰ
		//���Ǹ���ʼ[i,j],������
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
		//��ʼ��
		for (int i = 0; i <= len; i++){
			dp.push_back(i - 1);
		}

		for (int i = 1; i <= len; i++){

			for (int j = i - 1; j >= 0; j--){
				//�ַ���Ӱ����Ϊ���˸���λ��i=1ʱ�����ַ�1�������ַ������������ˣ���Ӱ��0��ʼ
				if (res[j][i - 1]){
					//Ҫ�õ���Сֵ������Ҫdp[i]ҲҪ��
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[len];


	}
};