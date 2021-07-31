class Solution {
public:
	//空间复杂度O(n),时间复杂度O(n^2)
	string reverseWords(string s) {
		string res;
		int len = s.size();
		int pos = 0;
		for (int i = len - 1; i >= 0; i = pos - 1){
			//取出多余的空格
			while (i >= 0 && s[i] == ' '){
				i--;
			}
			//如果开始有空格，直接回走到最开始，直接退出
			if (i<0){
				break;
			}
			//往前面找空格
			pos = s.rfind(' ', i);
			int j = pos + 1;
			//放到数组里
			while (j <= i){
				res += s[j++];
			}
			//没找到空格就不加空格
			if (pos != string::npos)
				res += ' ';
		}
		if (s[0] == ' '){
			res.pop_back();
		}
		return res;
	}
};

//优化
//O(1)空间复杂度，
class Solution {
public:
	string reverseWords(string s) {
		int fast = 0;
		int slow = 0;
		int len = s.size();
		//取出前面的空格
		while (fast<len&&s[fast] == ' '){
			fast++;
		}
		//取出中间多余空格
		while (fast<len){
			if (fast - 1>0 && s[fast - 1] == s[fast] && s[fast] == ' '){
				fast++;
			}
			else{
				s[slow++] = s[fast++];
			}
		}
		//取出后面的空格，
		//原字符串后面有空格，会在新字符串后面加一个空格，去掉
		if (s[slow - 1] == ' '){
			s.resize(slow - 1);
		}
		//原字符串后面没空格
		else{
			s.resize(slow);
		}
		//整体反转
		int num = s.size();
		int left = 0;
		int right = num - 1;
		while (left<right){
			swap(s[left++], s[right--]);
		}

		//字符反转
		for (int i = 0; i<num; i++){
			int j = i;
			while (j < num&&s[j] != ' '){
				j++;
			}
			int left = i;
			int right = j - 1;
			while (left<right){
				swap(s[left++], s[right--]);
			}
			i = j;
		}

		return s;

	}
};