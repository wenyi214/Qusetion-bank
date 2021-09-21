//找到小于等于n且低位到高位单调递增的最大数。
//暴力搜索，从n开始找，每次n--，保证数最大，现在只需要找位到高位递增的数。
//写一个函数判断，分出每一位，低位与高位比较。
class Solution {
public:
	bool check(int num){
		//低位
		int max = num % 10;
		while (num){
			num /= 10;
			//高位
			int m = num % 10;
			//比较，max为这一次的高位，就是下一次的低位
			if (max >= m){
				max = m;
			}
			else{
				return false;
			}

		}
		return true;
	}
	//暴力算法
	int monotoneIncreasingDigits(int n) {
		int i = n;
		for (; i >= 0; i--){
			if (check(i)){
				break;
			}
		}
		return i;

	}
};

//贪心：
//将整数转为字符串，如果str[i - 1]>str[i]，str[i - 1]--，str[i - 1]前面的数都可以写成9。
//比如：876，小于等于876的最大递增数为 876->869->799
//遍历需要从右往左遍历，如果从左往右遍历，前面的数仍然可能比后面的数大。
class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		string str = to_string(n);
		int len = str.size();
		//记录要变9的开始位置
		int index = len;
		for (int i = len - 1; i>0; i--){
			if (str[i - 1]>str[i]){
				//数字字符时连续的，字符减1相当于数字减1
				str[i - 1]--;
				index = i;
			}
		}
		//减1位置的低位所有数字都可以设为9
		for (int i = index; i<len; i++){
			str[i] = '9';
		}

		int x = atoi(str.c_str());
		return x;
		//return stoi(str);

	}
};