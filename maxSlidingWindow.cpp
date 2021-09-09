//ʹ�����ȶ��У�����ѡ�
//�����ֵpair����ֵkeyΪnums[i]��valueΪ����ֵ��
//��������ÿ���ƶ�һ��
//�����ӵ���һ������push�����
//����ѵĶѶ��������ֵ�����ǲ�һ���������������ֵ�����ܣ����������ǰ�档
//����Ҫ�ж϶ѵļ�ֵ��value���Ƿ���������䣬�������䣬������pop��ȥ��֪������������
//�����topֵ��
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0){
			return nums;
		}
		int len = nums.size();
		//�������ڽ���
		int start = 0;
		int end = k - 1;
		//����������
		vector<int> res;
		//���ȶ��У������ֵ
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i<k; i++){
			pq.push(make_pair(nums[i], i));
		}

		res.push_back(pq.top().first);
		start++, end++;

		while (end<len){
			pq.push(make_pair(nums[end], end));
			//top���ڻ��������pop��ȥ��
			while (pq.top().second<start){
				pq.pop();
			}
			res.push_back(pq.top().first);
			start++, end++;
		}
		return res;
	}
};