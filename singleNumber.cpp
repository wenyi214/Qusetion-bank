#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//����һ�����飬��¼ÿ����ÿһλ1�ĸ���
		int count[32] = { 0 };
		for (auto c : nums){
			//��¼1�ĸ���
			for (int i = 0; i<32; i++){
				if (c&(1 << i)){
					count[i]++;
				}
			}
		}
		int result = 0;
		//��λ����õ���Ӧ����
		for (int i = 0; i<32; i++){
			//��3Ϊ1˵������һ���������һλΪ1
			if (count[i] % 3){
				//ע��1�ǵ����
				result |= (1 << i);

			}
		}
		return result;


	}
};

int main(){

	return 0;
}