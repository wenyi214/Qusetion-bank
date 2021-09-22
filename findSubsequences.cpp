//根据示例发现，该结果求的是子集，但是需要去重。比如：不去重，[4，6，7]会出现两次。
//去重不能像上面的一个组合问题一样，先排序后去重，排序后，就不能得到和想在相同顺序的递增子序列了。
//并且去重是去除同一层相同的值，排序后可以比较前后，但是这里不能排序，可以用哈希表或者是一个数组记录，同一层是否已经使用过该元素。
//函数参数：
//由于同一元素不能重复取，取元素范围从startindex开始，每次递归从i + 1开始。
//
//递归返回：
//当startindex到数组最后，没有元素，递归返回。递归返回条件不用写，for循环，循环条件是再最后，会直接返回。
//
//单层递归逻辑：
//当path中没有元素要插入元素，当path最后一个元素比nums的第i个元素大于或者等于，插入元素。
//还需要用哈希表或者建立一个数组。判断同一层是否使用相同元素。
//
//难点主要是同一层不能使用相同元素，并且不能排序。用数组或者哈希表记录。
//同一层是在for循环里。递归会重新定义。 

class Solution {
public:
	void backtracing(vector<int>& nums, int startindex, int len, vector<vector<int>>& result, vector<int>& path){
		if (path.size()>1){
			result.push_back(path);
		}
		//去除同一层里相同的
		//同一层相同的是树的宽度，for循环里
		//每一次递归，是树的高度，都会重新定义
		//unordered_set<int> user;//去重
		int map[201] = { 0 };

		for (int i = startindex; i<len; i++){
			//当path元素不是一个并且小于path的值
			//当同一层有相同的
			if (path.size()>0 && nums[i]<path[path.size() - 1] || map[nums[i] + 100] == 1){
				continue;
			}
			//元素只有一个，和nums[i]>path最后一个
			//user.insert(nums[i]);
			map[nums[i] + 100] = 1;
			path.push_back(nums[i]);
			backtracing(nums, i + 1, len, result, path);
			path.pop_back();

		}
	}


	vector<vector<int>> findSubsequences(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> result;
		vector<int> path;
		backtracing(nums, 0, len, result, path);
		return result;

	}
};