//剑指 Offer 14- II. 剪绳子 II
//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
//每段绳子的长度记为 k[0], k[1]...k[m - 1] 。请问 k[0] * k[1] * ...*k[m - 1] 可能的最大乘积是多少？
//例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

//用贪心算法求剪绳子，自己写pow函数，在pow函数里求余。
//pow函数可以用快速幂来求


class Solution {
public:
	int mod = 1e9 + 7;
	//快速幂
	size_t Mypow(size_t x, int n){
		//返回值为size_t
		size_t res = 1;
		size_t b = x;
		int a = n;
		while (a){
			if (a % 2){
				res = res*b%mod;
			}
			b = b*b%mod;
			a /= 2;
		}

		return res;

	}
	int cuttingRope(int n) {

		if (n == 0){
			return 0;
		}
		if (n<4){
			return n - 1;
		}
		int x = n / 3;
		int y = n % 3;
		if (y == 0){
			return Mypow(3, x) % mod;
		}
		//余1，最后一个数是4，不能分割成有3的
		else if (y == 1){
			//将4*Mypow隐式转化为 sizt_t,测试用例中有超过int的
			return 4 * Mypow(3, x - 1) % mod;
		}
		//余2
		else{
			return 2 * Mypow(3, x) % mod;
		}




	}
};