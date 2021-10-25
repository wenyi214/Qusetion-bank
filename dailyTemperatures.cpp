

暴力解法：
两层循环，
外层循环遍历当前数组，里层循环，找后面出现的第一个大于当前的数
结果就是两个的距离。
超出时间限制
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int len = temperatures.size();
		vector<int> ans(len, 0);
		for (int i = 0; i< len; i++){
			int j = i;
			//找后面第一个出现大于temperatures[i]的下标
			for (; j<len; j++){
				if (temperatures[j] > temperatures[i]){
					break;
				}
			}
			if (j < len){
				ans[i] = j - i;//结果就是距离
			}
		}
		return ans;

	}
};

用栈：
一次遍历，单调递减栈
栈里的元素维护的都是小的值的下标，栈底元素值比栈顶元素值大。
当前值temperatures[i]大于栈顶元素值，当天后面比它大的气温天数，就是下标相减。
需要循环遍历，可能当前值temperatures[i]还大于栈顶后面的位置的值。
保存结果位置，就是栈顶元素保存的下标位置。
具体操作：保存天数，将栈顶元素pop，
当前值temperatures[i]小于栈顶元素值，将下标保存到栈中。
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int len = temperatures.size();
		//栈底元素值比栈顶元素值大。
		stack<int> st;

		vector<int> ans(len, 0);

		for (int i = 0; i<len; i++){
			//当temperatures[i]大于栈顶元素值
			while (!st.empty() && temperatures[st.top()] < temperatures[i]){
				//保存结果位置，就是栈顶元素保存的下标位置。
				ans[st.top()] = i - st.top();
				st.pop();
			}
			//当temperatures[i]小于栈顶元素值，将下标保存到栈中。
			st.push(i);
		}
		return ans;

	}
};


