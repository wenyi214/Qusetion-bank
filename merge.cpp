//需要排序，按照左边界从小到大排序
//如果由重叠需要合并。
//是否重叠是看当前左边界和上一个的右边界
//重叠是当前左边界小于等于上一个的右边界，这个时候需要合并，合并到当前，但是此时还不能收集结果，还需要和下一个比是否重叠，重叠的话还会需要合并。
//不重叠也不能直接收集结果，还需要和下一个比，看是否需要合并。
//总之不仅要和上一个比，还需要和下一个比。
//如果合并完最后一个，或者当前是最后一个与上一个没重叠，直接收集结果。
class Solution {
public:
	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len <= 1){
			return intervals;
		}
		//排序，左边界从小到大排序
		sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>> result;
		for (int i = 1; i<len; i++){
			if (intervals[i - 1][1] >= intervals[i][0]){
				//合并，选左边界最小的，右边界最大的
				intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
				intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
				//合并完之后是最后一个
				if (i + 1 == len){
					result.push_back(intervals[i]);
				}
				//不经要和上一个合并，还要和下一个比，确认是否要和下一个合并
				if (i + 1<len&&intervals[i][1]<intervals[i + 1][0]){
					result.push_back(intervals[i]);
				}

			}
			else{
				if (i == 1){//i从1开始，如果第0个与第1个比需要合并，直接入结果
					result.push_back(intervals[0]);
				}
				//最后一个不相等
				if (i + 1 == len){
					result.push_back(intervals[i]);
				}
				//不仅要和上一个不重复，还要和下一个不重复，次啊内收集到结果里
				if (i + 1<len&&intervals[i][1]<intervals[i + 1][0]){
					result.push_back(intervals[i]);
				}
			}
		}
		return result;
	}
};