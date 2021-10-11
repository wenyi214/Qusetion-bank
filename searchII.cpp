要求在log(N)时间范围内找出target下标

我可以将数组分成两段，两段中一段肯定是有序的，一段是无序
有序的一段，我们可以用二分查找，查找target的下标
无序的一段，我们继续分成两段，一段有序，一段无序，循环。
如何分成两段，也用二分查找。
[left, right]是有序的，[l, r]是无序的。
class Solution {
private:
	int FindNumber(vector<int>& nums, int left, int right, int target){
		while (left <= right){
			int mid = left + (right - left) / 2;
			if (nums[mid] < target){
				left = mid + 1;
			}
			else if (nums[mid] > target){
				right = mid - 1;
			}
			else{
				return mid;
			}
		}
		return -1;
	}
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		if (l > r){
			return -1;
		}
		int res = 0;
		int mid = 0;
		//[left,right]是有序的
		int left = 0;
		int right = 0;
		//外层二分，[l,r]是无序的，用二分，分出一个有序
		//再有序区域二分找
		while (l <= r){
			mid = l + (r - l) % 2;
			//右边有序
			if (nums[mid] < nums[l]){
				//[left,right]是有序的
				left = mid;
				right = r;
				//更新无序区域
				r = mid - 1;
			}
			//左边有序
			else if (nums[mid] >= nums[l]){

				left = l;
				right = mid;
				//更新无序区域
				l = mid + 1;
			}
			else{

			}
			//在有序区域找
			res = FindNumber(nums, left, right, target);
			//找到
			if (res != -1){
				break;
			}

		}
		return res;

	}
};