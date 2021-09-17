//暴力解法：
//因为一开始车的油是0，只能找一开始剩余的有res = gas[i] - cost[i]>0的开始看这个位置能不能走一圈。
//计算能否走一圈
//每次计算剩余的的油res = res + gas[i] - cost[i]，当res<0，肯定不能奏议圈，退出，找下一个加油站
//如果计算到最后res >= 0，返回下标值。

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		for (int i = 0; i<len; i++){
			if (gas[i] >= cost[i]){//其实位置i
				int j = (i + 1) % len;//记录下一个位置，是环，要余上len
				int res = 0;
				res = res + gas[i] - cost[i];//剩余油
				while (res >= 0 && j != i){
					res = res + gas[j] - cost[j];
					j += 1;
					j %= len;

				}
				if (res >= 0){
					return i;
				}


			}
		}
		return -1;

	}
};

//贪心算法：
//前提，一定可以走一圈
//计算[0，i]的剩余油res = gas[i] - cost[i]的和cursum。当cursum小于0，说明[0，i]都不能作为起始点，如果作为起始点到i位置就不能向前走了。起始点从i + 1开始，cursum从0开始计算。[j，i]cursum<0就从i + 1开始重新计算cursum
//将所有res加起来，小于0，一定不可以走一圈。
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int len = gas.size();
		int sum = 0;//总油剩余和
		int cursum = 0;//区间油剩余和
		int start = 0;//起始位置
		for (int i = 0; i<len; i++){
			sum += (gas[i] - cost[i]);
			cursum += (gas[i] - cost[i]);

			if (cursum<0){//如果小于0，开始位置再i+1处,前提能走一圈
				start = i + 1;
				cursum = 0;
			}

		}

		if (sum<0){//不能走一圈
			return -1;
		}
		return start;//能走一圈


	}
};