#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		size_t p1 = 0;
		size_t p2 = 0;
		while (p2<s.size()){
			while ((p2 + 1) != s.size() && s[p2 + 1] != ' '){
				p2++;
			}
			int left = p1;
			int right = p2;
			while (left<right){
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				left++, right--;
			}
			p2 += 2;
			p1 = p2;
		}
		return s;

	}
};

int main(){
	return 0;
}