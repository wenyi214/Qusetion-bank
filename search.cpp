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
	//���ֲ��ң��ҵ�һ������target���±�
	//�ҵ�һ������target���±�
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = 0;
		left = FindTarget(nums, target, true);
		right = FindTarget(nums, target, false);
		return right - left;

	}
};