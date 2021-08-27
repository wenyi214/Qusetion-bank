//这里有一个数学规律：
//1~9，数字只有1位数，从1开始，一共位数有9个。
//10~99，数字是2位数，从10开始，一共位数有
//10~19，数字两位，一共位数有20。
//20~29，数字两位，一共位数有20。
//......
//90~99，数字两位，一共位数有20。
//所以10~99，一共位数有9 * 10 * 2 = 180个
//100~999，数字是3位数，从100开始，一共位数有9 * 100 * 3 = 2700个
//总结就是：
//1~9，数字是1位数，从1开始。一共位数有9 * 1 * 1个
//10~99，数字是2位数，从10开始，一共位数有9 * 10 * 2个
//100~999，数字是3位数，从100开始，一共位数有9 * 100 * 3 = 2700个
//...
//
//要解这一题，主要是确定第n位数，具体是哪个数，然后确定是具体数里的具体哪一位。
//int digit = 1;//几位数
//size_t digitnum = 9;//在digit位数时，数字的总个数
//int start = 1;//从digit位数的那个数开始，1，10，100....
//
//具体哪个数，等于 start + 到start的个数。
//转化成求到start的个数 = (到start第一位的总位数 - 1) / 位数。为什么减1，求的距离。即1加多少等于5，加5 - 1 = 4。
//到start第一位的总位数 = n减去前面的总位数。
//while (n>digitnum){//不能等于，等于还会进入循环，就会往后找，但是等于时，说明已经在当前位digit个数里了。
//	//到start第一位的总位数
//	n -= digitnum;//因为只是求的位数为digit时的总个数，n是所有的总个数，所以要减digitnum。
//	digit++;
//	start *= 10;
//	digitnum = (size_t)9 * digit*start;//乘积超过int，强转成size_t
//}
//具体哪个数，num = start + (n - 1) / digit;
//具体这个数的哪一位
//看余数，count = (n - 1) % digit。

class Solution {
public:
	int findNthDigit(int n) {
		if (n == 0){
			return 0;
		}
		int digit = 1;//位数
		size_t digitnum = 9;//在digit位数时，数字的总个数
		int start = 1;//从digit位数的那个数开始，1，10，100....
		while (n>digitnum){//不能等于，等于还会进入循环，就会往后找，但是等于时，说明已经在当前位digit个数里了。
			//到start第一位的总位数
			n -= digitnum;//因为只是求的位数为digit时的总个数，n是所有的总个数，所以要减digitnum。
			digit++;
			start *= 10;
			digitnum = (size_t)9 * digit*start;//乘积超过int，强转成sizt_t
		}

		//当前位的那个数
		int num = start + (n - 1) / digit;//(n-1)是因为从第一位位开始的距离，距离，要减1。即1加多少等于5，加5-1=4。
		//这个数的哪一位
		int count = (n - 1) % digit;

		int x = digit - count - 1;
		int res = num % 10;
		while (x){
			num /= 10;
			res = num % 10;

			x--;
		}
		return res;

	}
};