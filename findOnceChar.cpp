#include<iostream>
#include<string.h>
#include<string>
using namespace std;
//利用计数排序思想
int main(){
	string s1;
	while (getline(cin, s1)){
		//创建一个数组
		int *key = new int[26];
		//初始化为0
		memset(key, 0, sizeof(int)* 26);
		//出现字符位置加1，相同字符会超过1
		for (size_t i = 0; i<s1.size(); i++){
			key[s1[i] - '0']++;
		}
		size_t i = 0;
		for (; i<s1.size(); i++){
			//循序找记录为1的
			if (key[s1[i] - '0'] == 1){
				break;
			}
		}

		if (i<s1.size()){
			delete[] key;
			cout << s1[i] << endl;
		}
		else{
			delete[] key;
			cout << -1 << endl;
		}
	}

	return 0;

}