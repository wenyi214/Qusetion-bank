

https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
右括号："("，左括号：")"。
方法一：暴力解法，判断s的所有子串是否是是有效括号，记录长度最大值
括号是成对出现的，最长有效括号子串一定是偶数。
如何判断：从大范围到小范围判断。



怎么判断：用栈，右括号入栈，遇到左括号右括号出栈，如果为最长有效括号子串，最后栈肯定为空。第一个就是左括号，肯定不是有效括号子串。
方法二：
状态定义：以第i位为结尾的最长有效子串长度。
转移方程：
如果是s[i] == "("右括号，肯定构不成最长有效子串。dp[i] = 0；
如果是s[i] == ")"左括号，往前可以匹配的位置找右括号"("，前面可以匹配的位置是：i - dp[i - 1] - 1，dp[i - 1]是以i - 1结尾的最长有效子串，是已经匹配过了，它的下一个位置没有匹配过。

如果 s[i - dp[i - 1] - 1] == "("，说明第i个")"有匹配的"("。
是求（i - dp[i - 1] - 1 ，i）之间的最长有效子串长度 与 （0 ，i - dp[i - 1] - 1）之间的有效子串长度和 加2
计算最长有效子串长度等于：dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2]；这里2是第i位和第s[i - dp[i - 1] - 1]匹配要加上2，
注意i - dp[i - 1] - 2可能小于0的情况，小于0，dp[i] = 2 + dp[i - 1] + 0；
if (s[i] == ')'){
	//数组下标大于0，可以匹配s[i]位置i - dp[i-1] -1，是否是"("
	//不是为0
	//是求i - dp[i-1] -1 到 i之间的最长有效子串长度 与 0 到i - dp[i-1] -1 之间的有效子串长度和 加2
	//2是因为i 和 i - dp[i-1] -1匹配 加两个"("")"
	if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
		if (i - dp[i - 1] - 2 >= 0)
			dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
		else//i - dp[i-1] - 2 < 0 
			dp[i] = 2 + dp[i - 1] + 0;
	}
}

初始化为  dp[0] = 0
返回值：dp所有值中的最大值
class Solution {
public:
	//动态规划
	int longestValidParentheses(string s) {
		int len = s.size();
		//前面以i结尾，最长有效长度
		vector<int> dp(len, 0);
		int maxcount = 0;
		for (int i = 1; i<len; i++){
			if (s[i] == ')'){
				//数组下标大于0，可以匹配s[i]位置i - dp[i-1] -1，是否是"("
				//不是为0
				//是求i - dp[i-1] -1 到 i之间的最长有效子串长度 与 0 到i - dp[i-1] -1 之间的有效子串长度和 加2
				//2是因为i 和 i - dp[i-1] -1匹配 加两个"("")"
				if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
					if (i - dp[i - 1] - 2 >= 0)
						dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
					else//i - dp[i-1] - 2 < 0 
						dp[i] = 2 + dp[i - 1] + 0;
				}
			}
			//找最大值
			if (dp[i] != 0 && maxcount < dp[i]){
				maxcount = dp[i];
			}
		}
		return maxcount;
	}
};


方法三：用栈

方法四：正向逆向结合法
先正向遍历
用两变量记录左括号和右括号的个数，
当左括号个数等于右括号个数时，说明正好匹配，子串长度等于2*左括号个数(或者右括号个数)
当左括号大于右括号个数，说明有一个左括号找不到匹配的右括号，左右括号个数置为0，重新记录。
为什么右括号个数可以大于左括号：因为认为后面有与之匹配的左括号
所以要反向遍历，防止一种情况：如下，下标2后面还有有效括号，但是没记录


反向遍历：左右括号情况颠倒
用两变量记录左括号和右括号的个数
当右括号个数等于左括号个数时，说明正好匹配，子串长度等于2*左括号个数(或者右括号个数)
当右括号大于左括号个数，说明有一个左括号找不到匹配的右括号，左右括号个数置为0，重新记录。

两种遍历才能得带最终的结果
class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		int left = 0;//左括号'('个数
		int right = 0;//右括号')'个数
		int maxcount = 0;//最大连续括号匹配个数
		int count = 0;//连续左右括号匹配个数
		//正向遍历
		for (int i = 0; i < len; i++){
			if (s[i] == '('){
				left++;
			}
			else{
				right++;
			}
			if (right > left){//多余的左括号，遍历后面肯定没有匹配的右括号
				right = 0;   //多余右括号，遍历后面可能还会有匹配的左括号
				left = 0;   //当前作为分隔，前面已经求出来左右子串了,求后面的连续左右括号

			}
			if (right == left){
				count = 2 * right;
				if (maxcount < count){
					maxcount = count;
					count = 0;
				}
			}
		}
		left = 0;
		right = 0;

		//反向遍历，防止正向遍历左括号没有匹配的右括号
		for (int i = len - 1; i >= 0; i--){
			if (s[i] == '('){
				left++;
			}
			else{
				right++;
			}
			if (right < left){//多余的左括号，遍历后面肯定没有匹配的左括号
				right = 0;   //多余左括号，遍历后面可能还会有匹配的右括号
				left = 0;   //当前作为分隔，前面已经求出来左右子串了

			}
			if (right == left){
				count = 2 * right;
				if (maxcount < count){
					maxcount = count;
					count = 0;
				}
			}
		}
		return maxcount;

	}
};

