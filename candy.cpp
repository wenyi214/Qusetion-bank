//这道题⽬⼀定是要确定⼀边之后，再确定另⼀边，例如⽐较每⼀个孩⼦的左边，然后再⽐较右边， 如果两边⼀起考
//虑⼀定会顾此失彼。
//先确认右边比左边大的数，右边比左边大，再左边基础上加1个糖果，ratings[i + 1]>ratings[i]，res[i] = res[i - 1] + 1
//再确认左边比右边大的数，左边比右边大，如果左边糖果数小于等于右边，等于右边糖果数加1。
//用一个数组保存糖果数，初始化为1
//
//只要右边评分⽐左边⼤，右边的孩⼦就多⼀个糖果，全局最优：相邻的孩⼦中，评分⾼的右孩⼦获
//得⽐左边孩⼦更多的糖果
//那么⼜要贪⼼了，局部最优：取candyVec[i + 1] + 1 和 candyVec[i] 最⼤的糖果数量，保证第i个⼩孩的糖果数量即
//⼤于左边的也⼤于右边的。全局最优：相邻的孩⼦中，评分⾼的孩⼦获得更多的糖果。
class Solution {
public:
	int candy(vector<int>& ratings) {
		int len = ratings.size();

		vector<int> res(len, 1);
		//计算右边比左边的糖果数
		for (int i = 1; i<len; i++){
			if (ratings[i]>ratings[i - 1]){
				res[i] = res[i - 1] + 1;
			}
		}

		//计算左边比右边的糖果数
		for (int i = len - 2; i >= 0; i--){
			if (ratings[i]>ratings[i + 1]){
				if (res[i] <= res[i + 1]){
					res[i] = res[i + 1] + 1;
				}
			}
		}
		//计算总数
		int ans = 0;
		for (auto c : res){
			ans += c;
		}
		return ans;

	}
};