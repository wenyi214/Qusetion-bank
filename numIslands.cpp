

�������������
��Ҫ���ڵ�ˮƽ����ʹ�ֱ���������ڵ��ַ�'1'��
��������������������Ҹ�����ÿһ���ַ����Ƿ�Ϊ1��

һ��ʼ��������ǣ�����ÿһ�����������е�1����ȥ���ѡ����ǻ����ظ��ģ��Ѿ���һ�������е�1��
���Ըñ������е�ֵ��
���ѻ���������е�ÿһ��1������ı�Ϊ����ֵ������1���������Ͳ����ҵ��ظ��ĵ����ˡ�
���������ҵ�1���϶���Ӧһ�����죬ֻ�ǵ�������ظ���
���ѵ������ǽ�ͬһ�������е�ÿһ��1����Ϊ����ֵ�������Ͳ������ظ����ˡ�
class Solution {
private:
	//�����ǽ�ͬһ�������е�ÿһ��1����Ϊ����ֵ
	void Bst(vector<vector<char>>& num, int i, int j, int row, int col){
		if (i >= row || j >= col || i <0 || j <0){
			return;
		}
		if (num[i][j] == '0' || num[i][j] == '2'){
			return;
		}
		//�ı�ֵ
		num[i][j] = '2';
		//ˮƽ�ʹ�ֱ����ҪѰ��
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
				//�ҵ������е�1����
				if (grid[i][j] == '1'){
					//�����ǽ�ͬһ�������е�ÿһ��1����Ϊ����ֵ����ֹ�ҵ��ظ�����
					Bst(grid, i, j, row, col);
					//�ҵ�1���϶�����һ�����졣
					ans++;
				}
			}
		}
		return ans;


	}
};

