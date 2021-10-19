

暴力解法，双循环，每次固定一边，计算所有区间的面积
class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;

		int side = 0;
		int maxside = 0;
		//一边不动，计算所有区间的面积
		for (int i = right; i>0; i--){
			for (int j = 0; j<i; j++){
				side = (i - j)*min(height[i], height[j]);
				maxside = max(side, maxside);
			}
		}
		return maxside;

	}
};

双指针法：
一指针1指针起始位置，一指针2指向末尾。
不断计算两指针间的面积
坐标如何更新？
由于面积受限于最短边：
当左指针值小于右指针值时，左指针加加
当左指针值大于右指针值时，右指针减减
class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;

		int maxside = 0;

		while (left < right){
			//做指针值小于右指针值
			while (left<right&&height[left] <= height[right]){
				maxside = max(height[left] * (right - left), maxside);
				left++;
			}
			//右指针值小于左指针值
			while (left<right&&height[right] <= height[left]){
				maxside = max(height[right] * (right - left), maxside);
				right--;
			}
		}

		return maxside;

	}
};

