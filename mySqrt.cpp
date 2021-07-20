#include<iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1){
			return x;
		}
		//为了分母不为0
		int left = 1;
		int right = x;
		while (left<right){
			int mid = left + (right - left) / 2;
			if (mid<(x / mid)){
				left = mid + 1;
			}
			else{
				//等于直接再里面返回
				if (mid == (x / mid)){
					return mid;
				}
				//大于找第一个大于的位置
				right = mid;
			}
		}
		return right - 1;

	}
};

int main(){
	return 0;
}