#include<iostream>
#include<string>
using namespace std;
//字符串逆置II

class Solution {
public:
	string reverseStr(string s, int k) {
		int i = 0;
		while (i<s.size()){

			int left = i;
			int right = i + k - 1;
			//如果右边超过边界，直接等于最后位置
			if (right >= s.size()){
				right = s.size() - 1;
			}
			//逆置
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