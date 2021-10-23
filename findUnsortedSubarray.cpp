

解法一：

将数据分成三段，numsA，numsB，numsC。numsB是无序的，范围[left，right]
将nums排序后，numsA和numsC顺序不会变，只有numsB的顺序会变。
从前到后，找到numsA相同的最大距离left，从后向前找numsB的最大距离right
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		//临时数组，排序
		vector<int> sortnums(nums);
		sort(sortnums.begin(), sortnums.end());

		int left = 0;
		int right = nums.size() - 1;

		//前面找相同的
		while (left <= right&&nums[left] == sortnums[left]){
			left++;
		}
		//后面的相同的
		while (left <= right&&nums[right] == sortnums[right]){
			right--;
		}

		return right - left + 1;
	}
};

方法二：
将数据分成三段，numsA，numsB，numsC。numsB是无序的，范围[left，right]
numsA里的数肯定全部小于numsB和numsC的值。
数组从大到小遍历，获取numsB，numC中的最小值min，找到最后一个值大于min的位置就是left
numsC里的数肯定全部大于numsB和numsA的值。
数组从小到大遍历，获取numsA，numB中的最大值max，找到最后一个值小于max的位置就是right
注意有序的情况：
有序left和right不会更新。
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int len = nums.size();
		int left = -1;
		int right = -1;
		int rightmin = INT_MAX;
		int leftmax = INT_MIN;
		for (int i = 0; i<len; i++){
			//找最后一个左边最大值，大于右边值的情况找到right
			//不能等于，等于位置不更新
			if (leftmax > nums[i]){
				right = i;
			}
			//更新最大值
			else{
				leftmax = nums[i];
			}
			//找最后一个右边的最小值，小于左边值的情况，找到left
			//不能等于，等于位置不更新
			if (rightmin < nums[len - i - 1]){
				left = len - i - 1;
			}
			//更新最小值
			else{
				rightmin = nums[len - i - 1];
			}
		}
		//有序left和right不会更新
		return right == -1 ? 0 : right - left + 1;

	}
};

