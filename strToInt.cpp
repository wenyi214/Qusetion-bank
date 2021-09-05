//先去除前面的空格
//只是数字或者是'-'和'+'才计算，否则返回0
//是负号计算结果，不一样，正好和不带正号结果一样
//如果是负号，往前加一格(防止有两个负号)，再循环计算数字和，最后乘一格负号
//如果是正号，也往前加一格(防止有两个正号)，再循环计算数字和，
class Solution {
public:
	int strToInt(string str) {
		int i = 0;
		//去除前面的空格
		while (isspace(str[i])){
			i++;
		}
		long long num = 0;
		if (isdigit(str[i]) || str[i] == '-' || str[i] == '+'){
			//如果是'-'号
			if (str[i] == '-'){
				//先往前走一格，不放循环条件里，反之两个--
				i++;
				//计算和
				while (isdigit(str[i]) && str[i]){
					num *= 10;
					num += (str[i] - '0');
					i++;
					//超过界限
					if (num + INT_MIN > 0){
						return INT_MIN;
					}
				}
				//负号乘-1
				num *= -1;

			}
			else{
				//带正号不带正号，计算结果一样
				//如果是'+'号，往前走一格，不放循环条件里，反之两个++
				if (str[i] == '+'){
					i++;
				}

				while (str[i] && isdigit(str[i])){

					num *= 10;
					num += (str[i] - '0');
					i++;
					if (num - INT_MAX > 0){
						return INT_MAX;
					}
				}

			}

		}

		return num;
	}
};