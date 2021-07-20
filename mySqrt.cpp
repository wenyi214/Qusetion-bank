#include<iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0 || x == 1){
			return x;
		}
		//Ϊ�˷�ĸ��Ϊ0
		int left = 1;
		int right = x;
		while (left<right){
			int mid = left + (right - left) / 2;
			if (mid<(x / mid)){
				left = mid + 1;
			}
			else{
				//����ֱ�������淵��
				if (mid == (x / mid)){
					return mid;
				}
				//�����ҵ�һ�����ڵ�λ��
				right = mid;
			}
		}
		return right - 1;

	}
};

int main(){
	return 0;
}