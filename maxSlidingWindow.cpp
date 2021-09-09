//使用优先队列，大根堆。
//保存键值pair，键值key为nums[i]，value为坐标值，
//滑动窗口每次移动一格。
//将增加的那一格数据push到堆里。
//大根堆的堆顶就是最大值，但是不一定是这个区间的最大值，可能，在这个区间前面。
//所以要判断堆的键值的value，是否在这个区间，不在区间，将数据pop出去，知道在这个区间里。
//保存堆top值。
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0){
			return nums;
		}
		int len = nums.size();
		//滑动窗口界限
		int start = 0;
		int end = k - 1;
		//保存结果数组
		vector<int> res;
		//优先队列，保存键值
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i<k; i++){
			pq.push(make_pair(nums[i], i));
		}

		res.push_back(pq.top().first);
		start++, end++;

		while (end<len){
			pq.push(make_pair(nums[end], end));
			//top不在滑动区间里，pop出去。
			while (pq.top().second<start){
				pq.pop();
			}
			res.push_back(pq.top().first);
			start++, end++;
		}
		return res;
	}
};