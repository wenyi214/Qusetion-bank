

字典序：从前往后依次比较。又一个大于，该字符串就是大于。
写一个排列的字典序大于当前，需要找到交换值，然后在后面找到最接近的且大于当前值的值，与其交换。
需要找到要交换的值。要交换的值后面至少有一个比它大的值，找到数组中索引最远，并且后面至少有一个比它大的值。
即找nums[k] < nums[k + 1]，找到最大索引最大k。
如果没有，说明是降序有序，按题意，升序排序返回。
找到交换位置，在后面找到值最接近nums[k]，且大于k的最大索引位置。即 nums[l] > nums[k]，k<l<nums.size()。肯定会有，至少是k + 1。
交换nums[k]和nums[l]的值。
还需要将k到nums.size()值升序排序。
由于nums[k] < nums[k + 1]，k是最大索引。说明k后面是降序排序。而nums[l] > nums[k]，k<l<nums.size()。说明(k，l)位置的值大于nums[k]，(l，num.size())位置的值肯定小于nums[k]。将nums[k]交换到nums[l]后，还是降序的。需要升序排序，将大的换到后面去，排成字典序最小。整体字典序才能正好大于上一次排列。
class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		int len = nums.size();
		if (len == 1){
			return;
		}
		int p1 = -1;//保存需要交换值的下标
		int p2 = -1;//保存值大于且最接近交换值的下标
		//找要交换值的下标
		for (int i = 0; i<len - 1; i++){
			if (nums[i] < nums[i + 1]){
				p1 = i;
			}
		}
		//如果没有，说明是降序，排序后返回
		if (p1 == -1){
			sort(nums.begin(), nums.end());
			return;
		}
		//找到值最接近交换值并且大于交换值
		for (int i = p1; i<len; i++){
			if (nums[p1] < nums[i]){
				p2 = i;
			}
		}
		//交换两值
		swap(nums[p1], nums[p2]);

		//需要将叫换值后面进行升序排序，后面是降序的，需要将大的放后面
		sort(nums.begin() + p1 + 1, nums.end());


	}
};

