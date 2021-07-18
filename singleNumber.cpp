#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//创建一个数组，记录每个数每一位1的个数
		int count[32] = { 0 };
		for (auto c : nums){
			//记录1的个数
			for (int i = 0; i<32; i++){
				if (c&(1 << i)){
					count[i]++;
				}
			}
		}
		int result = 0;
		//由位情况得到相应的数
		for (int i = 0; i<32; i++){
			//与3为1说明出现一次这个数这一位为1
			if (count[i] % 3){
				//注意1是倒序的
				result |= (1 << i);

			}
		}
		return result;


	}
};

int main(){

	return 0;
}