class Solution {
public:
	int solve(int n, int m, vector<int>& a) {
		// write code here
		const int M = 1e9 + 7;
		//��ʼ��
		int SumOdd = 0;//����iǰ�����������
		int Sumeven = 1;//����iǰ����ż�����
		//������
		vector<int> dp(n + 1, 0);

		//��¼����ˮ�Ӹ���
		int c = 0;
		for (int i = 1; i <= n; i++){
			//���Ѿ��������ˮ�ӻ��߲���ˮ�ӣ��ͼ������ϸ���
			if (c>m || i != a[c]){
				//�������
				//ż����
				if (i % 2 == 0){
					//Ϊ������
					dp[i] = SumOdd;
					//����ż����
					Sumeven += SumOdd;
				}
				//������
				else{
					//Ϊż����
					dp[i] = Sumeven;
					//����������
					SumOdd += Sumeven;
				}
			}
			else{
				//��ˮ��
				c++;
			}


		}
		return dp[n] % M;


	}
};