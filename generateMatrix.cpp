class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		//��ת��ʼλ��
		int startx = 0;
		int starty = 0;
		//�ŵ��������ֵ
		int count = 1;
		//�м����λ��
		int mid = n / 2;
		//Ȧ��
		int number = n / 2;
		//ÿһȦѭ������Ҫ����ÿһ���߱����ĳ���
		int len = 1;
		int i, j;
		while (number--){

			for (i = startx; i<starty + n - len; i++){
				res[startx][i] = count++;
			}
			for (j = starty; j<startx + n - len; j++){
				res[j][i] = count++;
			}
			for (; j>startx; j--){
				res[i][j] = count++;
			}
			for (; i>starty; i--){
				res[i][j] = count++;
			}

			startx++;
			starty++;
			//ÿ�λ�������Ԫ��
			len += 2;
		}
		//���Ϊ�����м����������ѭ�����������
		if (n % 2){
			res[mid][mid] = count;
		}
		return res;
	}
};