用两数记录左右括号个数
先放左括号，当右括号是剩余数大于左括号剩余数时，才可以放右括号，不然顺序不对。
class Solution {
private:
	vector<string> res;
	string path;
	void backtracing(int left, int right){//left记录左括号数，right记录右括号数

		if (left == 0 && right == 0){//左右括号都用完了
			res.push_back(path);
			return;
		}
		if (left>0){//有左括号先放左括号
			path += '(';
			left--;
			backtracing(left, right);
			path.pop_back();
			left++;
		}
		if (left < right){//左括号数少于右括号数，可以放一个右括号
			path += ")";
			right--;
			backtracing(left, right);
			right++;
			path.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		backtracing(n, n);
		return res;
	}
};