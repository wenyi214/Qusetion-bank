//寻找最大的跳跃范围，如果大于等于数组长度，返回真，反之，返回假
//i每次移动只能在cover的范围内移动，每移动⼀个元素， cover得到该元素数值（新的覆盖范围）的补充，让i继续
//移动下去
//每次范围cover取最大的范围，最大范围是下标加最大跳跃长度和上一次范围的最大值，max(nums[i]，cover)。
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size() - 1;
		if (len == 0){
			return true;
		}
		int i = 0;
		int cover = 0;//范围
		while (i <= cover){//取值是在范围里找的
			if (cover >= len){
				return true;
			}
			cover = max(i + nums[i], cover);//更新范围
			i++;

		}
		return false;

	}
};