#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int len = nums.size();
		int min = len + 1;//����һ�������ܴﵽ����
		int i = 0;//�������ڵ���ʼλ��
		int sum = 0;//��
		int sublen = 0;
		for (int j = 0; j<len; j++){
			sum += nums[j];
			// ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
			//������ھ�һֱ��ǰ��
			while (sum >= target){
				sublen = j - i + 1;// ȡ�����еĳ���
				min = min<sublen ? min : sublen;//����Сֵ
				sum -= nums[i++];// �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
			}

		}
		return min == len + 1 ? 0 : min;

	}
};

int main(){
	return 0;
}