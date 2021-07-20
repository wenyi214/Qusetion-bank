#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchTarget(vector<int> nums, int target, int key){
		int left = 0;
		int right = nums.size();
		//左闭右开
		while (left<right){
			int mid = left + (right - left) / 2;
			if (nums[mid]>target || (key&&nums[mid] >= target)){
				//right就是等于或者第一个大于target的值
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		return right;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		//赋初值
		res.push_back(-1);
		res.push_back(-1);
		if (nums.size() == 0){
			return res;
		}
		int left = searchTarget(nums, target, true);
		int right = searchTarget(nums, target, false) - 1;
		//如果再范围里，且值等于target返回left，right
		if (right<nums.size() && left<nums.size() && nums[left] == target&&nums[right] == target){
			res[0] = left;
			res[1] = right;

		}

		return res;

	}
};

int main(){
	return 0;
}