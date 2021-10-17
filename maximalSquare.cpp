�ҵ�˼·��
״̬���壺[i��j]����������������
ֻ�����õ���[i��j]���Ͻ�

��ǰλ��Ϊ0��dp[i][j] = 0
��ǰλ��Ϊ1���������Ͻ�����������δ��ڣ��������Ϊ0�������������߳���Ȼ�������
��ʼ����
dp[0][i] Ϊ��ǰֵ
dp[i][0] Ϊ��ǰֵ
class Solution {
private:
	//��߳���󳤶�
	int Judge(vector<vector<char>>& matrix, int i, int j, int len){
		int row = 0;
		int col = 0;
		int x = 0;
		for (int k = 1; k <= len; k++){
			if (matrix[i - k][j] == '1'){
				row++;
			}
			if (matrix[i][j - k] == '1'){
				col++;
			}
			//�ҵ����߳�
			if (matrix[i - k][j] == '0' || matrix[i][j - k] == '0'){
				break;
			}
		}
		x = min(col, row) + 1;
		return x;

	}
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		//������[i,j]Ϊ���½�������������
		vector<vector<int>> dp(row, vector<int>(col, 0));
		int ans = 0;
		//��ʼ����ֻ��һ��ֵ�����ǵ�ǰֵ
		for (int i = 0; i<row; i++){
			dp[i][0] = matrix[i][0] - '0';
			ans = max(ans, dp[i][0]);
		}
		for (int j = 0; j<col; j++){
			dp[0][j] = matrix[0][j] - '0';
			ans = max(ans, dp[0][j]);
		}

		int m = 0;
		int len = 0;
		for (int i = 1; i<row; i++){
			for (int j = 1; j<col; j++){
				m = dp[i - 1][j - 1];
				//��߳������Χ
				len = sqrt(m);
				//�����Ͻǹ��������Σ����ҵ�ǰֵ��Ϊ0
				//judge�����߳�
				if (m != 0 && matrix[i][j] == '1'){
					//�����߳�
					int x = Judge(matrix, i, j, len);
					dp[i][j] = x*x;
				}
				else{
					dp[i][j] = matrix[i][j] - '0';
				}
				//�õ����ֵ
				if (ans < dp[i][j]){
					ans = dp[i][j];
				}

			}

		}
		return ans;

	}
};



�Ž⣺
״̬���壺[i��j]��������α߳��� Ҳ��ʾ��(i, j) Ϊ���½ǵ������ε���ĿΪ x�����߳�Ϊ 1, 2, ..., x �������θ�һ������

ת�Ʒ��̣�
��������Σ�ֻ�������Ͻǣ���һ�еĵ�ǰ�У���һ�еĵ�ǰ�У�������������йء�
����������������ȫ1�ı߳�



ȡ��Сֵ���϶����Թ���������

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		//��������α߳�/[0��i]�߳�[0~i]�������θ���
		vector<vector<int>> dp(row, vector<int>(col, 0));
		int maxside = 0;
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				//��һ�е�һ�С���ֹԽ��
				if (i == 0 || j == 0){
					dp[i][j] = matrix[i][j] - '0';
				}
				//��ǰֵΪ0�����ܹ��������Σ��߳�Ϊ0
				else if (matrix[i][j] == '0'){
					dp[i][j] = 0;
				}
				else{
					//���Ͻǣ���һ�еĵ�ǰ�У���һ�еĵ�ǰ��
					//ȡ��Сֵ���϶����Թ���������
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;//������߳�
				}
				maxside = max(maxside, dp[i][j]);
			}
		}
		return maxside*maxside;

	}
};

