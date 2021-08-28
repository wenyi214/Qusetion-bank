//0~n - 1个数字在数组中，应该数字与数组下标对应。
//用二分查找，找到下标不对应的。
//当数值与下标相等时，说明不相等的数在后面。
//当数值与下标不相等时，说明可能就是当前这个数或者在前面。
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0;
		int right = nums.size();

		while (left<right){
			int mid = left + (right - left) / 2;
			/ 相等时，说明在后面
			if (nums[mid] == mid){
				left = mid + 1;
			}
			//不等时说明是当前这个数或者，在前面。
			//由于我right=nums.size，取不到，并且循环退出条件没有等于
			//right更新直接取mid
			else{
				right = mid;
			}
		}
		return right;

	}
};