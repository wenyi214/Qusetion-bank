//ÿ����Сֵȡ��������ͼ���
//����С�ѿ������׵õ���Сֵ������Сֵ���ѣ�ȡ�������
class Solution {
public:
	//��Сֵȡ���������
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minqueue;//С����
		for (auto c : nums){//���
			minqueue.push(c);
		}
		//�ҵ���Сֵ�����ѣ��ٽ���Сֵȡ�������
		while (k--){
			int tmp = minqueue.top();
			minqueue.pop();

			minqueue.push(-tmp);
		}
		int ans = 0;
		//���
		while (!minqueue.empty()){
			ans += minqueue.top();
			minqueue.pop();
		}

		return ans;

	}
};