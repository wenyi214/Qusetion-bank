#include<iostream>
using namespace std;
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		//记录退格符的个数
		int sindex = 0;
		int tindex = 0;
		//从后面开始遍历
		int i = s.size() - 1;
		int j = t.size() - 1;
		while (1){
			//去掉s退格符及其后面的值
			while (i >= 0){
				//如果是退格符，记录加1，后会位置会更新
				if (s[i] == '#'){
					sindex++;

				}
				//不是退格符，记录减1，
				else{
					if (sindex>0){
						sindex--;
					}
					//如果不是退格符并且，记录为0 就退出比较
					else{
						break;
					}
				}

				i--;
			}
			//去掉t退格符及其后面的值
			while (j >= 0){
				if (t[j] == '#'){
					tindex++;
				}
				else{
					if (tindex>0){
						tindex--;
					}
					else{
						break;
					}
				}

				j--;
			}
			//如果有一个还有字符比较，另外一个没有字符了。返回false
			if ((i<0 && j >= 0) || (i >= 0 && j<0)){
				return false;
			}
			//如果两个都没字符比较，退出，返回真
			if (i<0 && j<0){
				break;
			}
			//值不相等返回假
			if (s[i] != t[j]){
				return false;
			}
			//相等，说明还有值，比较后更新坐标
			i--, j--;
		}
		return true;

	}
};

int main(){
	return 0;
}