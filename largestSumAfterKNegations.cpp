//每次最小值取反，再求和即可
//用最小堆可以轻易得到最小值，将最小值出堆，取反后入堆
class Solution {
public:
	//最小值取反，和最大
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minqueue;//小根堆
		for (auto c : nums){//入堆
			minqueue.push(c);
		}
		//找到最小值，出堆，再将最小值取反后入堆
		while (k--){
			int tmp = minqueue.top();
			minqueue.pop();

			minqueue.push(-tmp);
		}
		int ans = 0;
		//求和
		while (!minqueue.empty()){
			ans += minqueue.top();
			minqueue.pop();
		}

		return ans;

	}
};