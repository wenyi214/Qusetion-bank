//Ҫ�����������ڡ�
//�ַ���Ҫ����������ȥ�ҡ�
//��ǵ�ǰλ���Ѿ����ʹ��������ȣ�����λ����Ϊ'\0'��֮��ػ��ݳ�ԭ��ֵ��
//��path������ȵ�ֵ��
//�����н������������Ϊ�������Ҷ�Ҫȥ��
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		_row = board.size();
		_col = board[0].size();
		_len = word.size();
		//���ٿռ䣬��wordһ����
		_path.resize(_len);
		for (int i = 0; i<_row; i++){
			for (int j = 0; j<_col; j++){
				//˵���ҵ�������true
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
		//Խ�磬ֵ���ȷ���false
		if (j >= _col || i >= _row || j<0 || i<0 || board[i][j] != word[n])
			return false;
		//����˵����board[i][j]==word[n]
		_path[n] = board[i][j];
		n++;
		//path��������word������˵���ҵ�
		if (n == _len){
			return true;
		}

		//��λ���Ѿ�����
		board[i][j] = '\0';
		bool res = backtracking(i + 1, j, board, word) || backtracking(i - 1, j, board, word) ||
			backtracking(i, j + 1, board, word) || backtracking(i, j - 1, board, word);
		//���ݣ�����λ�����ԭ��ֵ��path������1
		board[i][j] = _path[--n];
		//���ؽ��
		return res;
	}
};