

遍历所有括号，找出所有可能的子串，将有效括号的子串都保存起来。
利用回溯算法：
一个括号就只有取与不取两种选择。先选择不取，在选择取，所有情况都遍历一遍。
用一个变量保存左括号的个数，当遍历完，左括号等于0，说明子串括号有效。不为0 说明无效。
用一个map来保存所有有效括号子串，键值为子串长度，要得到删除数量最小的有效括号，说明子串长度需要最长的。
class Solution {
public:
	vector<string> ans;
	int visitedLeft = 0;
	map<int, set<string>> mm;
	void dfs(string s, int idx, string& t) {
		if (idx == s.size()) {
			if (0 == visitedLeft) {
				mm[t.size()].insert(t);
			}
			return;
		}

		if (s[idx] == '(') {
			//选择删除
			dfs(s, idx + 1, t);

			//选择保留
			t.push_back('(');
			visitedLeft++;
			dfs(s, idx + 1, t);
			visitedLeft--;
			t.pop_back();
		}
		else if (s[idx] == ')') {
			//选择删除
			dfs(s, idx + 1, t);

			//如果之前有记录左括号才可能保留右括号
			if (visitedLeft != 0) {
				t.push_back(')');
				visitedLeft--;
				dfs(s, idx + 1, t);
				visitedLeft++;
				t.pop_back();
			}
		}
		else {
			//非括号的字符 直接存入
			t.push_back(s[idx]);
			dfs(s, idx + 1, t);
			t.pop_back();
		}

	}

	vector<string> removeInvalidParentheses(string s) {
		string t;
		dfs(s, 0, t);

		auto tt = mm.rbegin();
		for (auto & e : tt->second) {
			ans.push_back(e);
		}

		return ans;
	}
};

这样超时了，需要剪枝
当有连续括号相同时，当只取一个括号时，取第一个括号和第二个括号，其实得到的结果会有很多相同的值。多了很多重复的操作。

我们需要在保留括号和删除括号前，先计算出有多数连续括号
在确定一次性保留或者删除多少括号，
下一次递归搜索之间从连续括号后面开始找就好了。
class Solution {
private:
	//set<string> st;
	int leftnum = 0;//剩余"("的个数，用来看是否匹配,为0说明匹配
	map<int, set<string>> mm;//map键值是有效括号长度，set是为了去重。
	void Dfs(const string& s, int index, string& t){
		//保存了所有有效的括号子串
		if (index == s.size()){
			//括号都匹配
			if (leftnum == 0){
				mm[t.size()].insert(t);
			}
			return;
		}
		//不是括号，是字符保存，因为要删除数量最小。字符不删除，操作少一次
		if (s[index] != '(' && s[index] != ')'){
			t += s[index];
			Dfs(s, index + 1, t);
			t.pop_back();
			//回溯直接返回
			return;
		}
		//找从当前位置开始相同括号的数量
		int k = 0;
		for (int i = index; i<s.size(); i++){
			if (s[index] == s[i]){
				k++;
			}
			else{
				break;
			}
		}
		//左括号
		if (s[index] == '('){
			//确认保留相同K个字符中的多数个
			for (int i = 0; i <= k; i++){
				//i=k，全保留，i=0，都不保留，i=1保留一个...
				for (int j = 0; j<i; j++){
					t += '(';
					leftnum++;
				}
				//下一次从连续括号后面开始找就好了
				Dfs(s, index + k, t);
				//回溯
				for (int j = 0; j<i; j++){
					t.pop_back();
					leftnum--;
				}
			}
		}
		else{
			//")"
			for (int i = 0; i <= k; i++){
				//需要剩余的左括号大于右括号的数量，才可以加入右括号
				//有多余的右括号肯定不匹配。
				if (i <= leftnum){
					for (int j = 0; j< i; j++){
						t += ')';
						leftnum--;
					}
					Dfs(s, index + k, t);
					for (int j = 0; j<i; j++){
						t.pop_back();
						leftnum++;
					}

				}
			}
		}
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		string t;
		Dfs(s, 0, t);
		vector<string> ans;
		//需要删除数量最小，需要有效括号长度最长
		//map最后加入的是长度最长的，所以从最后一个开始
		auto it = mm.rbegin();
		for (auto ch : it->second){
			ans.push_back(ch);
		}
		return ans;
	}
};

