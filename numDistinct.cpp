//力扣 115. 不同的子序列
//要定义一个二维数组，表示前s前i个和t的前j个
//状态定义：
//s字符串前i个字符串子串中等于t字符串前j个字符的个数
//转移方程：
//注意好定义就非常清楚了。i代表啥，j代表啥
//当s[i] == s[j]时，由两种情况
//取s[i]，结果就是前s[i - 1]个字符与t前j - 1个字符相同的个数dp[i - 1][j - 1]。只是最后加了一个字符，没增加方法数
//不取s[i]，结果就是s前i - 1个字符能够与t前j个字符相同子串个数 dp[i - 1][j]。不取s[i]，看s前i - 1字符中子串能与t前j字符相同的子串个数
//总个数：两个不是包含关系，是并列关系 因为一个取了s[i], 一个没有取s[i]，两则字符串个数肯定没有相同的。
//dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
//当s[i] != s[j]时
//只能看s的前i - 1字符子串中与t前j字符串相等个数 dp[i][j] = dp[i - 1][j]
//初始化：
//dp[i][0] = 1    s前i字符串构成空串，都有一种方法
//返回值
//dp[s.size()][t.size()]     总的s子串中与总的t相等个数
class Solution {
public:
	int numDistinct(string s, string t) {
		int len1 = s.size();
		int len2 = t.size();
		//无符号整形防止中间有数越界，越界从0开始
		vector<vector<size_t>> dp(len1 + 1, vector<size_t>(len2 + 1, 0));
		//初始化
		for (int i = 0; i <= len1; i++){
			dp[i][0] = 1;
		}
		//转移方程，前面推出后面，从前往后遍历
		for (int i = 1; i <= len1; i++){
			for (int j = 1; j <= len2; j++){
				//相等，缩影值要减1
				if (s[i - 1] == t[j - 1]){
					//取余不取
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

				}
				//不等
				else{
					dp[i][j] = dp[i - 1][j];
				}


			}
		}
		return dp[len1][len2];


	}
};