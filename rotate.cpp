

�򵥵㣺

�ҽ������ɣ���Ҫ�ǶԽ��߽������ɡ�������ѭ����x��y�ǽ����ġ�
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		//���ŶԽ��߽���
		for (int i = 0; i<row; i++){
			for (int j = 0; j<i; j++){
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		//���ҵ���
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

�����ģ�


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		if (row == 1 && col == 1){
			return;
		}
		//���ŶԽ��߽���
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
			//ÿ�η�Χ��С
			rowtmp--;
		}
		//���½���
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

