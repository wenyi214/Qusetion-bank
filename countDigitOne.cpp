//剑指 Offer 43. 1～n 整数中 1 出现的次数
class Solution {
public:
	int countDigitOne(int n) {
		//先从个位开始
		long long base = 1;
		//结果
		long long res = 0;
		//记录位值
		int key = 0;
		while (base <= n){
			long long a = n / base;
			//base后面
			long long b = n%base;
			//位值
			int key = a % 10;
			//base前面
			a /= 10;
			//三种情况
			if (key == 0)
				res += a*base;
			else if (key == 1)
				res += (a*base + b + 1);
			else
				res += ((a + 1)*base);
			//下一位
			base *= 10;
		}
		return res;


	}
};