

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		//��Ϊvv�����еĿռ�
		vv.resize(numRows);
		for (int i = 0; i<numRows; i++){
			//��λÿһ�п��ٿռ䣬����ʼ��Ϊ1
			vv[i].resize(i + 1, 1);

		}
		//�ӵڶ��п�ʼ
		for (int i = 2; i<numRows; i++){
			//��ÿһ�еĵ�һ�п�ʼ
			for (int j = 1; j<i; j++){
				//����ǰһ�е�ǰһ�м���ǰһ�еĵ�ǰ��
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}

		}
		return vv;

	}
};