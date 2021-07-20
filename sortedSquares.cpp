#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		//初始化，开辟的空间
		vector<int> res(nums.size(), 0);
		//前后指针
		int start = 0;
		int end = nums.size() - 1;
		//放最后
		int k = end;
		int x1 = 0;
		int x2 = 0;
		//要相等，中间这个元素也要处理
		while (start <= end){
			x1 = nums[start] * nums[start];
			x2 = nums[end] * nums[end];

			if (x1 >= x2){
				res[k--] = x1;
				start++;
			}
			else{
				res[k--] = x2;
				end--;
			}
		}
		return res;

	}
};

int main(){
	return 0;
}