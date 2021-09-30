//将nums值保存到unordered_set中，去重，unordered_set找值时间复杂度O(1)
//找连续序列的开始值。如果当前值连续小1的值不在unordered_set中，说明是起始位置。如果不是起始位置，找下一个值。
//然后，找连续大1的值的个数。
//保存最大个数。
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set myset(nums.begin(), nums.end());
		int ans = 0;
		for (auto c : nums){
			if (myset.find(c - 1) != myset.end()){
				continue;
			}
			int count = 1;
			while (myset.find(++c) != myset.end()){
				count++;
			}
			if (ans < count){
				ans = count;
			}
		}
		return ans;

	}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//将nums值保存到set中，还去重了。
		//unordered_set myset(nums.begin(),nums.end());
		unordered_set myset;
		for (const int& c : nums){
			myset.insert(c);
		}
		int ans = 0;
		for (const int& c : nums){
			//当前值的前一个在nums中，说明不是初始位置
			if (myset.count(c - 1) == 1){
				continue;
			}
			//前一个不在说明时连续最长序列的起始位置
			int count = 1;
			//找连续大的值，是否在nums中
			while (myset.count(++c) == 1){
				//在就个数加1
				count++;
			}
			//保存最大长度
			if (ans < count){
				ans = count;
			}
		}
		return ans;

	}
};