//213. 打家劫舍 II
//房屋成环，第一个和最后一个挨着了。
//做法：
//将前后两个分开来，讨论两种不成环的打家劫舍问题
//考虑包含⾸元素，不包含尾元素
//
//考虑包含尾元素，不包含首元素
class Solution {
public:
	int robit(vector<int>& nums, int start, int end){
		int len = end - start + 1;//长度
		vector<int> dp(len + 1, 0);
		dp[1] = nums[start];
		//第二个初始化是前两个中最大的
		dp[2] = max(nums[start], nums[start + 1]);
		for (int i = 3; i <= len; i++){
			//nums缩影下一个是nums[start+2],所以缩影是这个
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i - 1]);
		}
		return dp[len];
	}

	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0){
			return 0;
		}
		if (len == 1){
			return nums[0];
		}
		//如果只有两个，那个大就是哪个
		if (len == 2){
			return max(nums[0], nums[1]);
		}
		//讨论两种情况
		int front = robit(nums, 0, len - 2);//去掉最后一个
		int rear = robit(nums, 1, len - 1);//去掉第一个
		return max(front, rear);
	}
};