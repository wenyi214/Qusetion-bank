#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		//��ʼ�������ٵĿռ�
		vector<int> res(nums.size(), 0);
		//ǰ��ָ��
		int start = 0;
		int end = nums.size() - 1;
		//�����
		int k = end;
		int x1 = 0;
		int x2 = 0;
		//Ҫ��ȣ��м����Ԫ��ҲҪ����
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