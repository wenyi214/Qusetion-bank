方法1：同哈希表，记录元素个数
方法2：双指针法，时间复杂度O(n ^ 2)
方法3：排序后，动该元素位置对数组分成两段，用二分查找，在两段中，找当前位置的值。
方法4：快慢指针，和环形链表II解法相同。
不修改数组，不开辟空间。

快慢指针从0开始，当前位置的索引，就是下一次的位置，
数组中保存的是1~n的值，没有重复元素一定是一个单向链表。有重复元素，说明链表有环。


class Solution {
public:
	//使用快慢指针，当前位置的索引为下一个元素的位置(指向)，
	//因为有重复元素，所以有环
	int findDuplicate(vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		//当前元素的索引就是下一个的位置
		do{
			slow = nums[slow];
			fast = nums[nums[fast]];

		} while (slow != fast);
		//找入环点，
		slow = 0;
		while (slow != fast){
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;

	}
};