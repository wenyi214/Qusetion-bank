#include<iostream>
#include<string>
using namespace std;
//�ַ�������II

class Solution {
public:
	string reverseStr(string s, int k) {
		int i = 0;
		while (i<s.size()){

			int left = i;
			int right = i + k - 1;
			//����ұ߳����߽磬ֱ�ӵ������λ��
			if (right >= s.size()){
				right = s.size() - 1;
			}
			//����
			while (left<right){
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				left++;
				right--;
			}

			i += (2 * k);

		}
		return s;

	}
};

int main(){
	return 0;
}