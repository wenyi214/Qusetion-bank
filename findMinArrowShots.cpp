//�Ƚ�������߽��С��������ã������ñȽ������Ƿ��ཻ
//���һ�����ұ߽���ڵ���һ������߽磬˵���ཻ����Ҫ���������ཻ��������С���ұ߽硣���ཻ��������������ཻ������С�߽������ཻ���ɡ�
//������һ�����ұ߽�С��һ������߽磬˵�����ཻ����������1
class Solution {
public:
	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int len = points.size();
		if (len == 0){
			return 0;
		}
		sort(points.begin(), points.end(), cmp);
		int result = 1;//һ��������Ҫһ֧��
		for (int i = 1; i<len; i++){
			if (points[i][0]>points[i - 1][1]){//û���ཻ��
				result++;
			}
			else{
				//Ҫ������ȡ���ཻ���������С�����ཻ������ȡ�ཻ�����ɱ߽����Сֵ
				points[i][1] = min(points[i][1], points[i - 1][1]);//������С������
			}
		}
		return result;

	}
};