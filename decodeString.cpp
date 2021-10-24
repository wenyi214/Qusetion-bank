

解码，"[]"里的是要解码的字符串，利用栈先进后出原理，可以找到整个字符串，再找前面的数字，就知道解码的个数。
由于不用解码的字符串不会用"[]"括起来，并且，前面没有数字，我们将解码后的字符串保存到栈中，最后栈中的字符串就是结果。

解法：
遇到数字，字符，' [ '入栈，
遇到' ] '进行解码。
1.先获得这个字符串，
遇到最近的 ' [ '就获得了字符串。
2.在获得前面的数字，注意不一定是一位数
3.再将解码后的字符串重新放到栈中。
最后栈中的字符串就是结果
class Solution {
public:
	//将解码后的字符串，放到栈中在返回
	string decodeString(string s) {

		int len = s.size();
		string ans;
		stack<char> st;
		for (int i = 0; i < len; i++){
			//说明"[]"里的字符串需要解码
			if (s[i] == ']'){
				//将"[]"字符串取出来，栈push是反的
				string tmp;
				while (st.top() != '['){
					tmp += st.top();
					st.pop();
				}
				st.pop();//将'['pop出来

				//将数字取出来
				int p = 1;
				//取出第一个数字
				int x = st.top() - '0';
				st.pop();
				//可能前面还有数字
				while (!st.empty() && isdigit(st.top())){
					int t = st.top() - '0';
					p = p * 10;
					x = (t * p + x);//乘10加x
					st.pop();
				}

				//将字符串重新放到栈中，并且放x个
				for (int i = 0; i<x; i++){
					//从末尾开始放
					for (int j = tmp.size() - 1; j >= 0; j--){
						st.push(tmp[j]);
					}
				}
			}
			else{
				st.push(s[i]);

			}

		}
		//将解码后的字符串，放到string中返回
		//如果栈push，会是反的，
		//先开辟空间从后往前放
		int st_len = st.size();
		ans.resize(st_len);
		while (st_len){
			ans[st_len - 1] = st.top();
			st.pop();
			st_len--;
		}

		return ans;
	}
};

