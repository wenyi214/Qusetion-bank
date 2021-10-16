
遍历0~n每一个数，求每一个数1的个数
class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> ans(n + 1, 0);

		for (int i = 0; i <= n; i++){
			int m = i;
			int count = 0;
			while (m){
				m = m&(m - 1);
				count++;
			}
			ans[i] = count;
		}
		return ans;

	}
};

动态规划：最低位
在[0，i]中找到一个数j，正好是i的二进制序列是j二进制序列1的个数加1，或者等于j二进制序列1的个数
当i最低位为1，二进制序列1的个数等于j = i >> 1 加1
当i最低位为1，二进制序列1的个数等于j = i >> 1 的二进制序列1的个数，j最后一位为0，1的个数没变
class Solution {
public:
	//在[0，i]中找到一个数j，正好是i的二进制序列是j二进制序列1的个数加1，或者等于j二进制序列1的个数
	//当i最低位为1，二进制序列1的个数等于j = i>>1 加1
	//当i最低位为1，二进制序列1的个数等于j = i>>1 的二进制序列1的个数
	vector<int> countBits(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		for (int i = 1; i <= n; i++){
			//最低位为1
			if (i & 1){
				dp[i] = dp[i / 2] + 1;
			}
			else{
				dp[i] = dp[i / 2];
			}
		}
		return dp;
	}
};

