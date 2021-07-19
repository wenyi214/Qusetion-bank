#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	const string map[10] = {
		"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
	};
public:
	void backtracking(string& digits, vector<string>& result, string path){
		if (path.size() == digits.size()){

			result.push_back(path);
			return;
		}
		//求出字符对应的数字'2'->2
		int pos = digits[path.size()] - '0';

		for (int i = 0; i<map[pos].size(); i++){

			path += map[pos][i];
			backtracking(digits, result, path);
			path.erase(path.size() - 1, 1);


		}

	}

	vector<string> letterCombinations(string digits) {
		//收集结果
		vector<string> v;
		if (digits.size() == 0){
			return v;
		}

		string path;
		backtracking(digits, v, path);

		return v;

	}
};

int main(){

	return 0;
}