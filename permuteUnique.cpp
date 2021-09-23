//因为有重复的元素，这里涉及到需要去重的操作。
//去重的操作和组合去重的操作类似，由于这里没有严格规定连个数之间的相对位置。可以先排序后去重。同一层元素相同，不进行排列。
//如果前后两元素相等，并且，前面这个元素没有使用，说明还会拿前面的元素，会有相同的结果。此时不进行排列。
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracing(int len, vector<int>& nums, vector<int>& usered){
		if (path.size() == len){
			result.push_back(path);
			return;
		}
		for (int i = 0; i<len; i++){
			//如果前一个没使用过，并且还和现在一样，会出现相同结果
			if (i>0 && usered[i - 1] == 0 && nums[i] == nums[i - 1]){
				continue;
			}

			if (usered[i] == 0){
				usered[i] = 1;
				path.push_back(nums[i]);
				backtracing(len, nums, usered);
				usered[i] = 0;
				path.pop_back();
			}
		}
	}
	static bool cmp(int a, int b){
		return a<b;
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//先排序，将相同的元素放一起
		sort(nums.begin(), nums.end(), cmp);
		int len = nums.size();
		//标记元素是否使用
		vector<int> usered;
		usered.resize(len);
		backtracing(len, nums, usered);
		return result;

	}
};