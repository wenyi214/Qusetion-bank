

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		//先为vv开辟行的空间
		vv.resize(numRows);
		for (int i = 0; i<numRows; i++){
			//在位每一行开辟空间，并初始化为1
			vv[i].resize(i + 1, 1);

		}
		//从第二行开始
		for (int i = 2; i<numRows; i++){
			//从每一行的第一列开始
			for (int j = 1; j<i; j++){
				//等于前一行的前一列加上前一行的当前列
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}

		}
		return vv;

	}
};