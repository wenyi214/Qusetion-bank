//栈的压入与弹出
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int len = pushV.size();
		stack<int> s;
		int j = 0;
		for (int i = 0; i<len; i++){
			//不同，入栈
			s.push(pushV[i]);
			//如果相同，不停出栈，
			while (!s.empty() && s.top() == popV[j]){
				s.pop();
				j++;
			}
		}
		return s.empty();

	}
};