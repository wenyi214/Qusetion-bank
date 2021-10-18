

计算的是当前位置可以积水的量，当前列可以接水的量。

主要思路：求出当前位置，左边的最大值和右边的最大值，当中的较小值m，如果大于当前值，当前列能积雨水量为 m - height[i]
左边最大值和右边最大值中的最小值是最大水量。
动态规划：
状态定义：
两个数组：left[i]第i位左边的最大值，right[i]第i位右边的最大值。
转移方程：
当前位置的积水量，左边的最大值和右边的最大值，当中的较小值m，如果小于当前值，当前列能积雨水量为 m - height[i]
初始话：
第i位左边最大值，从左往右遍历，保存左边最大值。
第i位右边最大值，从右往左遍历，保存右边最大值。
返回值：
积水量的和。
class Solution {
public:
	//动态规划
	int trap(vector<int>& height) {
		int len = height.size();

		int leftmax = 0;
		int rightmax = 0;

		vector<int> left(len, 0);//保存第i位左边最大值
		vector<int> right(len, 0);//保存第i位右边最大值
		//从左往右遍历，第i位左边最大值
		for (int i = 1; i<len; i++){
			leftmax = max(leftmax, height[i - 1]);
			left[i] = leftmax;
		}
		//从右往左遍历，第j位右边的最大值
		for (int j = len - 2; j >= 0; j--){
			rightmax = max(rightmax, height[j + 1]);
			right[j] = rightmax;
		}
		int ans = 0;
		for (int i = 1; i<len; i++){
			//左右两边最大值里的较小值
			int tmp = min(left[i], right[i]);
			if (tmp > height[i]){
				ans += tmp - height[i];//求当前列的积水量
			}
		}

		return ans;
	}
};

双指针法：
一个指针1指向最开始，一个指针2指向末尾。
指针1的值和指针2中的值小的那个先走，意思也是左右两边较小值这边是边界。
并且左边或者右边的最大值，来计算当前列的水量。
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		int left = 0;
		int right = len - 1;
		int leftmax = 0;
		int rightmax = 0;
		int ans = 0;
		while (left < right){
			//左指针值小于右指针值时遍历，说明左边低，可能漏水
			while (left<right&&height[left] <= height[right]){
				//能进入循环说明，左边最大值小于右边最大值
				leftmax = max(leftmax, height[left]);
				//左边最大值减当前列的值
				if (height[left] < leftmax){
					ans += (leftmax - height[left]);
				}
				left++;
			}
			//右指针值小于左指针值时遍历，说明右边低，可能漏水
			while (left<right&&height[left] >= height[right]){
				rightmax = max(height[right], rightmax);
				if (height[right] < rightmax){
					ans += (rightmax - height[right]);
				}
				right--;
			}

		}
		return ans;

	}
};

