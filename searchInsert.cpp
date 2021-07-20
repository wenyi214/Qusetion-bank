#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		while (left<right){
			int mid = left + (right - left) / 2;
			if (nums[mid] == target){
				return mid;
			}
			else if (nums[mid]>target){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		return right;

	}
};
int main(){
	return 0;
}