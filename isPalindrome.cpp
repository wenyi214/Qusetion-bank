#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0){
			return true;
		}
		string t = s;
		int left = 0;
		int right = t.size() - 1;
		while (left<right){
			//判断是否是数字，或者字母，不是向前走
			while (left<right&&!(isalpha(t[left]) || isdigit(t[left]))){
				left++;
			}
			//判断是否是数字，或者字母，不是向后走
			while (left<right&&!(isalpha(t[right]) || isdigit(t[right]))){
				right--;
			}
			//都转成小写进行比较
			t[left] = tolower(t[left]);
			t[right] = tolower(t[right]);

			if (t[left] != t[right]){
				return false;
			}
			left++;
			right--;
		}
		return true;

	}
};

int main(){
	return 0;
}