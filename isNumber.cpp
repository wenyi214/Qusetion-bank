//超级考虑我们是否能考虑所有情况的题
//你试试吧

class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		int len = s.size();
		//去除前面的空格
		while (isspace(s[i])){
			i++;
		}
		int count = 0;//记录点的个数
		//只有第一个字符为这四种情况可以进来判断
		if (isdigit(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.'){
			//第一个字符为这三种i++
			if (s[i] == '.' || s[i] == '-' || s[i] == '+'){
				//记录.的个数
				if (s[i] == '.'){
					count++;
				}
				i++;
				//+.和-.也可以往后判断
				if (s[i - 1] != '.'&&s[i] == '.'){
					i++;
					count++;
				}
				//如果后面没字符了，或者不是数字返回false
				if (i == len | !isdigit(s[i])){
					return false;
				}
			}

			int flag = 0;//记录e的个数
			//到这就肯定是数字了
			while (i<len){
				//数字.e也符合要求，e.不符合，先判断.
				//前面没e和.时
				//数字.符合要求，所以不加i==len时返回false
				if (flag == 0 && s[i] == '.'&&count<1){
					i++;
					count++;
				}
				if (flag == 0 && (s[i] == 'e' || s[i] == 'E')){
					i++;

					//e后面必须有数字
					if (i == len){
						return false;
					}
					if (s[i] == ' '){
						return false;
					}
					//可以时符号，符号后必须有数字
					if (s[i] == '-' || s[i] == '+'){
						i++;
						if (i == len){
							return false;
						}
					}
					flag = 1;

				}

				//if(!isdigit(s[i])&&(flag==1||s[i]!='e'||s[i]!='E'))
				if (!isdigit(s[i])){
					//去除最后的空格
					while (i<len&&isspace(s[i])){
						i++;
					}
					if (i == len)
						return true;
					else
						return false;
				}
				i++;
			}
			return true;

		}
		return false;






	}
};