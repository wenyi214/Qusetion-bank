#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int len = nums.size();
		int min = len + 1;//定义一个不可能达到的数
		int i = 0;//滑动窗口的起始位置
		int sum = 0;//和
		int sublen = 0;
		for (int j = 0; j<len; j++){
			sum += nums[j];
			// 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
			//如果大于就一直往前移
			while (sum >= target){
				sublen = j - i + 1;// 取子序列的长度
				min = min<sublen ? min : sublen;//找最小值
				sum -= nums[i++];// 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
			}

		}
		return min == len + 1 ? 0 : min;

	}
};

int main(){
	return 0;
}