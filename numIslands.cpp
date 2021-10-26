

深度优先搜索：
需要相邻的水平方向和垂直方向有相邻的字符'1'。
利用深度优先搜索，查找附近的每一个字符，是否为1。

一开始，我想的是，遍历每一个，找数组中的1，再去深搜。但是会有重复的，已经是一个岛屿中的1。
可以该变数组中的值。
深搜会遍历岛屿中的每一个1，将其改变为其他值，再找1，遍历，就不会找到重复的岛屿了。
再数组中找到1，肯定对应一个岛屿，只是岛屿可能重复。
深搜的作用是将同一个岛屿中的每一个1，改为其他值。这样就不会有重复的了。
class Solution {
private:
	//作用是将同一个岛屿中的每一个1，该为其他值
	void Bst(vector<vector<char>>& num, int i, int j, int row, int col){
		if (i >= row || j >= col || i <0 || j <0){
			return;
		}
		if (num[i][j] == '0' || num[i][j] == '2'){
			return;
		}
		//改变值
		num[i][j] = '2';
		//水平和垂直，都要寻找
		Bst(num, i, j + 1, row, col);
		Bst(num, i + 1, j, row, col);
		Bst(num, i - 1, j, row, col);
		Bst(num, i, j - 1, row, col);

	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		int ans = 0;
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				//找到数组中的1深搜
				if (grid[i][j] == '1'){
					//作用是将同一个岛屿中的每一个1，该为其他值，防止找到重复岛屿
					Bst(grid, i, j, row, col);
					//找到1，肯定会有一个岛屿。
					ans++;
				}
			}
		}
		return ans;


	}
};

