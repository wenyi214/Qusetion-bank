class Solution {
public:
	int FindTarget(vector<int>& nums, int target, bool judge){
		int left = 0;
		int right = nums.size();
		while (left<right){
			int mid = left + (right - left) / 2;
			if (nums[mid]>target || (judge&&nums[mid] >= target)){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		return right;
	}
	//二分查找，找第一个等于target的下标
	//找第一个大于target的下标
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = 0;
		left = FindTarget(nums, target, true);
		right = FindTarget(nums, target, false);
		return right - left;

	}
};