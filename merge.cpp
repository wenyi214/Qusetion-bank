//��Ҫ���򣬰�����߽��С��������
//������ص���Ҫ�ϲ���
//�Ƿ��ص��ǿ���ǰ��߽����һ�����ұ߽�
//�ص��ǵ�ǰ��߽�С�ڵ�����һ�����ұ߽磬���ʱ����Ҫ�ϲ����ϲ�����ǰ�����Ǵ�ʱ�������ռ����������Ҫ����һ�����Ƿ��ص����ص��Ļ�������Ҫ�ϲ���
//���ص�Ҳ����ֱ���ռ����������Ҫ����һ���ȣ����Ƿ���Ҫ�ϲ���
//��֮����Ҫ����һ���ȣ�����Ҫ����һ���ȡ�
//����ϲ������һ�������ߵ�ǰ�����һ������һ��û�ص���ֱ���ռ������
class Solution {
public:
	static bool cmp(vector<int>& p1, vector<int>& p2){
		return p1[0]<p2[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len <= 1){
			return intervals;
		}
		//������߽��С��������
		sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>> result;
		for (int i = 1; i<len; i++){
			if (intervals[i - 1][1] >= intervals[i][0]){
				//�ϲ���ѡ��߽���С�ģ��ұ߽�����
				intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
				intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
				//�ϲ���֮�������һ��
				if (i + 1 == len){
					result.push_back(intervals[i]);
				}
				//����Ҫ����һ���ϲ�����Ҫ����һ���ȣ�ȷ���Ƿ�Ҫ����һ���ϲ�
				if (i + 1<len&&intervals[i][1]<intervals[i + 1][0]){
					result.push_back(intervals[i]);
				}

			}
			else{
				if (i == 1){//i��1��ʼ�������0�����1������Ҫ�ϲ���ֱ������
					result.push_back(intervals[0]);
				}
				//���һ�������
				if (i + 1 == len){
					result.push_back(intervals[i]);
				}
				//����Ҫ����һ�����ظ�����Ҫ����һ�����ظ����ΰ����ռ��������
				if (i + 1<len&&intervals[i][1]<intervals[i + 1][0]){
					result.push_back(intervals[i]);
				}
			}
		}
		return result;
	}
};