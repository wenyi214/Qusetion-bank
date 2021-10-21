

以第i行，计算出从最开始所有列数连续1的值。
用栈， 84. 柱状图中最大的矩形的思路
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		int row = matrix.size();
		if (row == 0){
			return 0;
		}
		int col = matrix[0].size();
		//保存当前行该列1的个数
		vector<int> nums(col, 0);
		stack<int> st;
		int maxside = 0;
		for (int i = 0; i<row; i++){
			int high = 0;
			int wide = 0;
			for (int j = 0; j<col; j++){
				//求第i行，当前列1的个数
				if (matrix[i][j] == '1'){
					nums[j]++;
				}
				else{
					nums[j] = 0;
				}
				//求面积
				while (!st.empty() && nums[st.top()] > nums[j]){
					//高度
					high = nums[st.top()];
					st.pop();
					//宽度
					if (st.empty()){
						wide = j;
					}
					else{
						wide = j - st.top() - 1;
					}
					//面积
					maxside = max(maxside, high*wide);
				}
				st.push(j);
			}
			while (!st.empty()){
				high = nums[st.top()];
				st.pop();

				if (st.empty()){
					wide = col;
				}
				else{
					wide = col - st.top() - 1;
				}
				maxside = max(maxside, high*wide);
			}

		}
		return maxside;

	}
};

