//���ص��������
//��452.�����������ļ�������������
//�밴��߽簴��С�����������ﲻ�ܵ���
//��������ұ߽����һ������߽磬˵���ཻ��ɾ����ɾ���������ģ�����Ϊ������������¸���Ŀռ䡣��¼��С����������䡣����ɾ������1
//��������ұ߽�С�ڵ���һ������߽磬˵�����ཻ�����ô���
class Solution {
public:

	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];

	}

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len == 0){
			return 0;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		int count = 0;
		for (int i = 1; i<len; i++){
			if (intervals[i][0]<intervals[i - 1][1]){//�ཻ
				count++;
				//ȡ�ұ߽�С�ģ�Ϊ��������������ռ�
				intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
			}
			else{

				//intervals[i][1]=max(intervals[i-1][1],intervals[i][1]);
			}

		}
		return count;

	}
};