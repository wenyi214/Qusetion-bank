class Solution {
public:
	int solve(int n, int m, vector<int>& a) {
		// write code here
		const int M = 1e9 + 7;
		//初始化
		int SumOdd = 0;//跳到i前所有奇数层和
		int Sumeven = 1;//跳到i前所有偶数层和
		//保存结果
		vector<int> dp(n + 1, 0);

		//记录遇到水坑个数
		int c = 0;
		for (int i = 1; i <= n; i++){
			//当已经跨过所有水坑或者不是水坑，就计算跳上个数
			if (c>m || i != a[c]){
				//两种情况
				//偶数层
				if (i % 2 == 0){
					//为奇数和
					dp[i] = SumOdd;
					//更新偶数和
					Sumeven += SumOdd;
				}
				//奇数层
				else{
					//为偶数和
					dp[i] = Sumeven;
					//更新奇数和
					SumOdd += Sumeven;
				}
			}
			else{
				//是水坑
				c++;
			}


		}
		return dp[n] % M;


	}
};