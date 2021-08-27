//状态定义：
//s的前i - 1个字符串是否与p的j - 1个字符串匹配。
//转移方程：
//当p[j - 1]是字符时，dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1], 看s和p的最后两数是否相等，在看前面的字符串是否匹配。
//当p[j - 1]是“.”时，dp[i][j] = dp[i - 1][j - 1]，因为“.”可以代表任何字符。
//当p[j - 1]是“*”时，此时要和p[j - 1]和p[j - 2]看作一个字符。两种情况。
//当不用这两个时，就是p[i - 2] != s[j - 1]，情况与去掉p的两个字符的情况。dp[i][j - 2]
//当使用多次这两字符时，即p[i - 2] == s[j - 1]和p[i - 2] == "."时，情况为dp[i - 1][j]。去掉s的最后一个字符。为什么p不用去掉字符，因为要继续匹配。如s = “aaaaaaa”，p = “a*”的情况。
//两种时并列关系：转移方程为：dp[i][j] = (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) || dp[i][j - 2]
//初始化：
//dp[0][0] = true, s空串，p空串。
//dp[0][j]当偶数为“*”，并且后面接下来的偶数为“*”时，p可以构成空串，即dp[0][j] = true;
//for (int i = 2; i <= len2; i += 2){
//	dp[0][i] = dp[0][i - 2] && (p[i - 1] == '*');
//	if (dp[0][i] == false){
//		break;
//	}
//}
//返回值：
//s字符串是否与p所有字符串匹配。dp[s.size()][p.size()]

	class Solution {
	public:
		bool isMatch(string s, string p) {
			int len1 = s.size();
			int len2 = p.size();
			vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
			dp[0][0] = true;
			//s为空串，要是p为空串，如果偶数位为*,
			//主要是第二位位*，然后接下来的偶数位都为*,就可以置空。
			for (int i = 2; i <= len2; i += 2){
				dp[0][i] = dp[0][i - 2] && (p[i - 1] == '*');
				if (dp[0][i] == false){
					break;
				}
			}

			for (int i = 1; i <= len1; i++){
				for (int j = 1; j <= len2; j++){
					if (p[j - 1] == '*'){
						//匹配一次或多次dp[i-1][j]&&s[i-1]==p[j-2]，情况可能是这种s="aaaa",p="a*",肯定要s[i-1]==p[j-2]
						//等于dp[i-1][j]有两种情况，s[i-1]与p[j-2]相等，因为p[j-1]=*，和p[i-2]=="."，因为.代表任何字符
						//不匹配dp[i][j-2],删掉后面两个
						dp[i][j] = (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) || dp[i][j - 2];
					}
					else{
						if (s[i - 1] == p[j - 1] || p[j - 1] == '.'){
							dp[i][j] = dp[i - 1][j - 1];
						}

					}
				}
			}
			return dp[len1][len2];


		}
	};