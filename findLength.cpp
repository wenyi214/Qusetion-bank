//状态定义：
//
//数组A以i - 1结尾和数组B以j - 1结尾的公共连续最长子序列。(这里的最长子序列不是所有里面最长的，因为连续，所以必须以A第i - 1个结尾，B的第j - 1个结尾时的最长的)，
//
//结尾的意思是：最后一个元素必须是A的第i - 1个元素和最后一个元素必须是B的第j - 1个元素。
//
//转移方程：
//
//dp[i][j]只能由dp[i - 1][j - 1]求得。
//
//当A[i - 1] == B[j - 1]时，dp[i][j] = dp[i - 1][j - 1] + 1。
//
//当A[i - 1] != B[j - 1]时，dp[i][j] = 0。必须以A[i - 1]和B[j - 1]结尾，两个都不相等了，为0。
//
//初始化：
//
//dp[i][0] = 0，B数组没有元素
//
//dp[0][j] = 0，A数组没有元素
//
//返回值：
//
//所有元素里值最大的


class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		//初始化
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		int m = 0;
		//转移方程
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				//缩影
				if (nums1[i - 1] == nums2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;

				}

				//题目要求要连续的，这样就不连续了
				// else{
				//     dp[i][j]=dp[i-1][j];
				// }
				//找返回值
				if (m<dp[i][j]){
					m = dp[i][j];
				}

			}
		}


		return m;

	}
};