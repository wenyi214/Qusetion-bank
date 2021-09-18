//���Ǻ����е����
//������������¼����5�飬10�飬20��Ǯ������
//����һ��ʼû����Ǯ�����bills[0]>5��ֱ�ӷ���false��
//�������5������5���������ֱ�ӻ�ȡ������Ҫ����
//�������10������10�����������Ҫ����5�飬���û��5�飬ֱ�ӷ���false
//�������20������20�����������Ҫ�ȿ�������10 + ����5���������ٿ���������5����������Ϊ5���������10��Ҳ������20���Ƚ�10�������ȽϺá�
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		if (bills[0]>5){
			return false;
		}
		int fivecount = 0;
		int tencount = 0;
		int twetycount = 0;

		for (int i = 0; i<bills.size(); i++){
			if (bills[i] == 5){//5��ֱ�ӻ�ȡ
				fivecount++;
			}
			else if (bills[i] == 10){//10��
				tencount++;
				if (fivecount == 0){//û��5��ֱ�ӷ���false
					return false;
				}
				else{//��5�飬5��������1
					fivecount--;
				}
			}
			else{//20
				twetycount++;
				if (tencount == 0){//û��10��
					if (fivecount<3){
						return false;
					}
					else{
						fivecount -= 3;
					}
				}
				else{//��10��
					if (fivecount == 0){//û��5��
						return false;
					}
					else{
						tencount--;
						fivecount--;
					}
				}
			}

		}
		return true;

	}
};