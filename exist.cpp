//要求连续，相邻。
//字符，要到上下左右去找。
//标记当前位置已经访问过，如果相等，将该位置置为'\0'，之后回回溯成原来值。
//用path保存相等的值。
//将所有结果或起来，因为上下左右都要去找
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		_row = board.size();
		_col = board[0].size();
		_len = word.size();
		//开辟空间，和word一样大
		_path.resize(_len);
		for (int i = 0; i<_row; i++){
			for (int j = 0; j<_col; j++){
				//说明找到，返回true
				if (backtracking(i, j, board, word)){
					return true;
				}
			}
		}
		return false;
	}
private:
	int n = 0;
	string _path;
	int _row;
	int _col;
	int _len;
	bool backtracking(int i, int j, vector<vector<char>>& board, string& word){
		//越界，值不等返回false
		if (j >= _col || i >= _row || j<0 || i<0 || board[i][j] != word[n])
			return false;
		//到这说明，board[i][j]==word[n]
		_path[n] = board[i][j];
		n++;
		//path个数等于word个数，说明找到
		if (n == _len){
			return true;
		}

		//该位置已经访问
		board[i][j] = '\0';
		bool res = backtracking(i + 1, j, board, word) || backtracking(i - 1, j, board, word) ||
			backtracking(i, j + 1, board, word) || backtracking(i, j - 1, board, word);
		//回溯，将该位置设回原来值，path个数减1
		board[i][j] = _path[--n];
		//返回结果
		return res;
	}
};