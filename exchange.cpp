//首尾指针，
//在前面找偶数，找到后，在后面找奇数，交换
//注意不要越界，和退出条件
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int p1 = 0;
		int p2 = nums.size() - 1;
		while (p1<p2){
			//找偶数
			while (p1<p2&&nums[p1] % 2 == 1){
				p1++;
			}
			//找奇数
			while (p1<p2&&nums[p2] % 2 == 0){
				p2--;
			}
			//交换
			swap(nums[p1], nums[p2]);

		}
		return nums;

	}
};