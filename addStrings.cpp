#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {

		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		//��λ
		int next = 0;
		int sum = 0;

		int x1 = 0;
		int x2 = 0;
		string res;
		while (end1 >= 0 || end2 >= 0){
			//�����һλС��0��������ֵ����0
			if (end1 >= 0){
				x1 = num1[end1] - '0';
				end1--;
			}
			else{
				x1 = 0;
			}
			if (end2 >= 0){
				x2 = num2[end2] - '0';
				end2--;
			}
			else{
				x2 = 0;
			}
			//�������
			sum = x1 + x2 + next;
			//������9����λ����1���������0
			if (sum>9){
				sum %= 10;
				next = 1;
			}
			else{
				next = 0;
			}

			res += (sum + '0');


		}
		//���������󣬽�λ����1����Ҫ�ӵ��ַ�����
		if (next == 1){
			res += '1';
		}
		//��Ҫ����
		int left = 0;
		int right = res.size() - 1;
		while (left<right){
			char tmp = res[left];
			res[left] = res[right];
			res[right] = tmp;
			left++;
			right--;
		}
		return res;


	}
};

int main(){
	return 0;
}