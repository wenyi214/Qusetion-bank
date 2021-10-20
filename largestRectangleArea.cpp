

暴力解法：
从当前位置向左右两边找，找到小于当前位置的值为止，计算面积，面积为当前位置值乘以左右两边位置的宽度，计算所有面积的最大值。
栈：
根据暴力解法，是要找两边小于当前值的下标，计算出宽度，高度就是当前值。
从数组开始位置遍历，栈里保存的是数组的下标。
入栈：当数组值大于栈顶值入栈，出栈：当数组当前值小于栈顶值，出栈。
栈顶前面的值肯定小于栈顶值，数组当前值小于当前值，
这样就找到栈顶值左右两边小于栈顶值的位置，就知道了宽度(i - 栈顶元素 - 1)。再乘以栈顶位置数组值，就求出当前位置的最大面积。

由于是从数组开始遍历，可能遍历完栈中还有元素。
还需要求出栈中元素的面积，
栈中元素一定是较小值，出栈，宽度，右边肯定可以走到数组末尾，因为栈右边元素数组值肯定大于当前值，为数组总长减去新栈顶元素位置再减1。

栈中元素先出栈，出栈后为空，出栈元素为数组中最小元素，面积为数组总长乘以当前值。
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {

		int len = heights.size();

		stack<int> st;
		int wide = 0;
		int high = 0;
		int maxside = 0;
		//遍历
		for (int i = 0; i<len; i++){
			//当前元素大于栈顶元素
			while (!st.empty() && heights[st.top()] > heights[i]){
				//出栈
				high = heights[st.top()];
				st.pop();
				//求宽度
				if (st.empty()){
					//为空，宽度就是当前位置值
					wide = i;
				}
				else{
					//不为空，当前位置减去，新栈顶位置减1
					wide = i - st.top() - 1;
				}
				maxside = max(high*wide, maxside);
			}
			st.push(i);
		}
		//遍历完，栈可能不为空,将栈元素弹出，并计算面积
		while (!st.empty()){
			//先出栈
			high = heights[st.top()];
			st.pop();
			//求宽度
			//最小值出栈，宽度就是数组长度
			if (st.empty()){
				wide = len;
			}
			//出栈位置右边到末尾距离，都可以加上，到栈顶位置
			else{
				wide = len - st.top() - 1;
			}
			maxside = max(high*wide, maxside);
		}
		return maxside;


	}
};


