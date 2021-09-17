//�����ⷨ��
//��Ϊһ��ʼ��������0��ֻ����һ��ʼʣ�����res = gas[i] - cost[i]>0�Ŀ�ʼ�����λ���ܲ�����һȦ��
//�����ܷ���һȦ
//ÿ�μ���ʣ��ĵ���res = res + gas[i] - cost[i]����res<0���϶���������Ȧ���˳�������һ������վ
//������㵽���res >= 0�������±�ֵ��

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		for (int i = 0; i<len; i++){
			if (gas[i] >= cost[i]){//��ʵλ��i
				int j = (i + 1) % len;//��¼��һ��λ�ã��ǻ���Ҫ����len
				int res = 0;
				res = res + gas[i] - cost[i];//ʣ����
				while (res >= 0 && j != i){
					res = res + gas[j] - cost[j];
					j += 1;
					j %= len;

				}
				if (res >= 0){
					return i;
				}


			}
		}
		return -1;

	}
};

//̰���㷨��
//ǰ�ᣬһ��������һȦ
//����[0��i]��ʣ����res = gas[i] - cost[i]�ĺ�cursum����cursumС��0��˵��[0��i]��������Ϊ��ʼ�㣬�����Ϊ��ʼ�㵽iλ�þͲ�����ǰ���ˡ���ʼ���i + 1��ʼ��cursum��0��ʼ���㡣[j��i]cursum<0�ʹ�i + 1��ʼ���¼���cursum
//������res��������С��0��һ����������һȦ��
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int len = gas.size();
		int sum = 0;//����ʣ���
		int cursum = 0;//������ʣ���
		int start = 0;//��ʼλ��
		for (int i = 0; i<len; i++){
			sum += (gas[i] - cost[i]);
			cursum += (gas[i] - cost[i]);

			if (cursum<0){//���С��0����ʼλ����i+1��,ǰ������һȦ
				start = i + 1;
				cursum = 0;
			}

		}

		if (sum<0){//������һȦ
			return -1;
		}
		return start;//����һȦ


	}
};