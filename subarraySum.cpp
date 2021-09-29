//�����ⷨ�������Ӽ�
//����ѭ����һ��ѭ�����ƴ���һ����ʼ��
//�ڶ���ѭ�������Ӽ��ͣ�ע���Ǵӵ�һ��ѭ����ʼ���ӵ�0��
//Ϊʲô����0��ʼ�������0��ʼ����Ķ��Ǵ�0��ʼ���Ӽ���
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int count = 0;

		for (int start = 0; start < nums.size(); start++){
			int sum = 0;
			//Ϊʲô����0��ʼ�������0��ʼ��ÿһ���Ӽ����Ǵ�0��ʼ
			//������Ҫ�����Ӽ���0��ʼ
			for (int end = start; end >= 0; end--){
				sum += nums[end];
				if (sum == k){
					++count;
				}
			}
		}
		return count;

	}
};

//���ù�ϣ�����Ż� + ǰ׺��
//�Ӽ��͵���k��
//�Ӽ����������[j�� i]����pre[i]Ϊ0~i�ĺͣ�pre[j - 1]Ϊ0~i - 1d�ĺ͡�
//����[j��i]�Ӽ��͵���  pre[i] - pre[j - 1] ��
//�����Ӽ��͵���k����  pre[i] - pre[j - 1] = k ����>   pre[j - 1] = pre[i] - k��
//����ת��Ϊ  ������[0��i]���ֽں͵��� pre[i] - k�ĸ����͡�
//��һ����ϣ���¼��
//��ֵΪ�ֽںͣ�valueΪ[0��i]�Ӽ���Ϊkey���ֵĸ�����
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int count = 0;
		//һ��ʼ��Ϊ0
		m[0]++;
		int sum = 0;
		for (auto& a : nums){
			//ǰ׺�ͣ�ֻ��Ҫ��֮ǰ�Ļ����ϣ�����nums[i]
			sum += a;
			//��[0,i]ǰ׺�͵���sum-k�ĸ�������������map��m.second��
			if (m.find(sum - k) != m.end()){
				count += m[sum - k];
			}
			//��ǰ׺�ͼ���map���ߴ��ڵĻ�����������1
			m[sum]++;
		}
		return count;

	}
};