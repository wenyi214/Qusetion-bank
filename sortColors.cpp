

将0交换到前面，将2交换到后面，1就在自己在的位置了。
我的思路：
一个指针p1指向数字最开始，从后往前遍历，找0，交换到前面不是0的位置
同理：一个指针指向末尾，从头往后遍历，找2，交换到后面不是2的位置。
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		for (int i = len - 1; i>left; i--){
			if (nums[i] == 0){
				while (left < i&&nums[left] == 0){
					left++;
				}
				if (left > i){
					break;
				}
				swap(nums[left], nums[i]);
			}
		}

		for (int i = 0; i<right; i++){
			if (nums[i] == 2){
				while (right>i&&nums[right] == 2){
					right--;
				}
				if (right < i){
					break;
				}
				swap(nums[i], nums[right]);
			}
		}


	}
};

双指针法：
一次遍历

将0和2放好就可以了
i可变量，p1前面为0，p2后面为2。不包括p1和p2。
当nums[i]为0，和nums[p1]交换，p1++，i++。
当nums[i]为2，和nums[p2]交换，p2--，i不更新，可能交换回来的是2。还需要判断
当nums[i]为1，直接更新i，i++。
当i > p2时，遍历结束，可能p2是0。
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();

		int p1 = 0;
		int i = 0;
		int p2 = len - 1;
		//p2位置可能为0
		while (i <= p2){
			if (nums[i] == 0){
				//位置不一样交换
				if (i != p1){
					swap(nums[i], nums[p1]);
				}
				p1++;
				//可以更新i，交换回来的肯定不是0
				//i和p1是一起走的，p1位置肯定不是0
				i++;
			}
			else if (nums[i] == 2){
				swap(nums[i], nums[p2]);
				p2--;
				//不要更新i，可能交换回来的还是2
			}
			else{
				i++;
			}

		}

	}
};

