//找重叠区间个数
//和452.用最少数量的箭引爆气球类似
//想按左边界按从小到大排序，这里不能等于
//如果区间右边界大于一区间左边界，说明相交，删除，删除右区间大的，可以为后面的区间六下更大的空间。记录下小区间的有区间。并且删除数加1
//如果区间右边界小于等于一区间左边界，说明不相交，不用处理。
class Solution {
public:

	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];

	}

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len == 0){
			return 0;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		int count = 0;
		for (int i = 1; i<len; i++){
			if (intervals[i][0]<intervals[i - 1][1]){//相交
				count++;
				//取右边界小的，为后面区间六更大空间
				intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
			}
			else{

				//intervals[i][1]=max(intervals[i-1][1],intervals[i][1]);
			}

		}
		return count;

	}
};