class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		int x = matrix.size();
		int y = matrix[0].size();//���㺯��������
		if (x == 0 && y == 0){
			return res;
		}
		int count = x*y;//���һ���ж���Ԫ��
		int k = 0;//��¼�뵽����������Ԫ�ظ���
		res.resize(count);//���ٿռ�

		int startx = 0;//�������鿪ʼλ��
		int starty = 0;

		int len = 1;//����ǰ�պ󿪣�Ҫ���Ԫ�ظ�����ǰ�պ󿪣����׳�ʼֵ1
		int i, j;

		while (k<count){
			//�����ж�������Ҫk�ĸ���С��Ԫ���ܸ���
			for (i = startx; k<count&&i<starty + y - len; i++){//starty+y��Ҫ��starty�±꿪ʼ���Լ�y
				res[k++] = matrix[startx][i];//�����Ѿ������˵ĸ���  
			}

			for (j = starty; k<count&&j<startx + x - len; j++){
				res[k++] = matrix[j][i];
			}

			for (; k<count&&i>startx; i--){
				res[k++] = matrix[j][i];
			}

			for (; k<count&&j>starty; j--){
				res[k++] = matrix[j][i];
			}
			if (k == count - 1){//���Ϊn*n�������涼������룬���һ��������ϣ���ʱ�˳����������
				break;
			}
			startx++;
			starty++;
			len += 2;
		}
		if (k == count - 1){//�����м�λ��
			int mid = x / 2;
			res[k] = matrix[mid][mid];
		}
		return res;

	}
};