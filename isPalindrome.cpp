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
			//�ж��Ƿ������֣�������ĸ��������ǰ��
			while (left<right&&!(isalpha(t[left]) || isdigit(t[left]))){
				left++;
			}
			//�ж��Ƿ������֣�������ĸ�����������
			while (left<right&&!(isalpha(t[right]) || isdigit(t[right]))){
				right--;
			}
			//��ת��Сд���бȽ�
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