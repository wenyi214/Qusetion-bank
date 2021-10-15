暴力解法：
class Solution {
public:
	//暴力解法
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		int mul = 1;
		int m = INT_MIN;
		for (int i = 0; i<len; i++){
			mul = 1;
			for (int j = i; j<len; j++){
				mul *= nums[j];
				if (mul > m){
					m = mul;
				}
			}
		}
		return m;

	}
};

状态定义：1.以第i位结尾的最大值，和最小值
为什么定义两个？考虑负数情况
转移方程
最小值有三种情况：前i - 1个最小值是正数，当前值是负数smalldp[i - 1] * nums[i]，前i - 1个最小值是负数，第i个是负数nums[i]，当前值是负数，前i - 1个最大值是正数bigdp[i - 1] * nums[i]。
最大值也有三种情况：前i - 1个最大值是正数，当前值是负数 = num[i]，前i - 1个最大值是负 / 正数，第i个是负 / 正数 = bigdp[i - 1] * nums[i]，当前值是负数，前i - 1个最小值是负数 = smalldp[i - 1] * nums[i]。
smalldp[i] = min(bigdp[i - 1] * nums[i], min(smalldp[i - 1] * nums[i], nums[i]));
bigdp[i] = max(smalldp[i - 1] * nums[i], max(bigdp[i - 1] * nums[i], nums[i]));


class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int len = nums.size();
		int ans = nums[0];
		//状态定义：1.以第i位结尾的最大值，和最小值
		vector<int> smalldp(len, 0);//最小值
		vector<int> bigdp(len, 0);//最大值

		smalldp[0] = bigdp[0] = nums[0];//初始化

		for (int i = 1; i < len; i++){
			//转移方程
			//最小值有三种情况：前i-1个最小值是正数，当前值是负数smalldp[i-1]*nums[i]，前i-1个最小值是负数，第i个是负数nums[i]，当前值是负数，前i-1个最大值是正数bigdp[i-1]*nums[i]。
			//最大值也有三种情况：前i-1个最大值是正数，当前值是负数 = num[i]，前i-1个最大值是负/正数，第i个是负/正数 = bigdp[i-1] * nums[i]，当前值是负数，前i-1个最小值是负数=smalldp[i-1]*nums[i]。
			smalldp[i] = min(bigdp[i - 1] * nums[i], min(smalldp[i - 1] * nums[i], nums[i]));
			bigdp[i] = max(smalldp[i - 1] * nums[i], max(bigdp[i - 1] * nums[i], nums[i]));
			//求最大值
			if (bigdp[i] > ans){
				ans = bigdp[i];
			}
		}
		return ans;

	}
};

