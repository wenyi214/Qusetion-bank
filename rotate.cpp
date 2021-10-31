

简单点：

找交换规律，主要是对角线交换规律。用两层循环，x，y是交换的。
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		//沿着对角线交换
		for (int i = 0; i<row; i++){
			for (int j = 0; j<i; j++){
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		//左右倒序
		for (int i = 0; i<row; i++){
			int left = 0;
			int right = matrix[0].size() - 1;
			while (left < right){
				swap(matrix[i][left], matrix[i][right]);
				left++, right--;
			}
		}

	}
};

我做的：


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		if (row == 1 && col == 1){
			return;
		}
		//沿着对角线交换
		int r = 0;
		int l = col - 1;
		int key = row / 2;
		int rowtmp = row;
		while (r < key){
			int i = 1;
			while (r + i < rowtmp){
				swap(matrix[r + i][l], matrix[r][l - i]);
				i++;
			}
			int j = 1;
			while (r + j < rowtmp){
				swap(matrix[r + i - 1][l - j], matrix[r + j][l - i + 1]);
				j++;
			}
			r++, l--;
			//每次范围缩小
			rowtmp--;
		}
		//上下交换
		int line = 0;
		while (line < col){
			int start = 0;
			int end = row - 1;
			while (start < end){
				swap(matrix[start][line], matrix[end][line]);
				start++, end--;
			}
			line++;
		}

	}
};

