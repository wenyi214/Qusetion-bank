//求峰值的个数，前面一段大于等于0，后面一段小于0，前面一段小于与等于0，后面一段大于0，峰值数增加
//当最左边有一个结点，[2, 5]，峰值数为2，最左边有一个相同的结点。所以返回值初始化为1，当最左边有一个结点。
//所以可以针对序列[2, 5]，可以假设为[2, 2, 5]，这样它就有坡度了即preDiff = 0

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int len = nums.size();
		if (len == 1){
			return 1;
		}

		int res = 1;//峰值个数，最左边有一个结点
		int i = 0;
		int start = 0;//前面一段差值，一开始为0，最左边有一个相同结点
		int end = 0;//后一段差值
		while (i<len - 1){
			end = nums[i + 1] - nums[i];
			if ((start <= 0 && end>0) || (start >= 0 && end<0)){//峰值数增加情况
				start = end;//前一段的差值   
				res++;
			}

			i++;

		}
		return res;
	}
};