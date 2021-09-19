//先将区域按左边界从小到大排序好，这样好比较区域是否相交
//如果一气球右边界大于等于一气球左边界，说明相交，需要保存所有相交气球里最小的右边界。想相交必须和所有气球相交。和最小边界气球相交即可。
//如果如果一气球右边界小于一气球左边界，说明不相交，剑个数加1
class Solution {
public:
	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int len = points.size();
		if (len == 0){
			return 0;
		}
		sort(points.begin(), points.end(), cmp);
		int result = 1;//一个气球需要一支剑
		for (int i = 1; i<len; i++){
			if (points[i][0]>points[i - 1][1]){//没有相交的
				result++;
			}
			else{
				//要和气球取余相交，必须和最小区域相交，所以取相交其余由边界的最小值
				points[i][1] = min(points[i][1], points[i - 1][1]);//保存最小的区间
			}
		}
		return result;

	}
};