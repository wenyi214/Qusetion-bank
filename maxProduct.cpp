�����ⷨ��
class Solution {
public:
	//�����ⷨ
	int maxProduct(vector<int>& nums) {
		int len = nums.size();
		int mul = 1;
		int m = INT_MIN;
		for (int i = 0; i<len; i++){
			mul = 1;
			for (int j = i; j<len; j++){
				mul *= nums[j];
				if (mul > m){
					m = mul;
				}
			}
		}
		return m;

	}
};

״̬���壺1.�Ե�iλ��β�����ֵ������Сֵ
Ϊʲô�������������Ǹ������
ת�Ʒ���
��Сֵ�����������ǰi - 1����Сֵ����������ǰֵ�Ǹ���smalldp[i - 1] * nums[i]��ǰi - 1����Сֵ�Ǹ�������i���Ǹ���nums[i]����ǰֵ�Ǹ�����ǰi - 1�����ֵ������bigdp[i - 1] * nums[i]��
���ֵҲ�����������ǰi - 1�����ֵ����������ǰֵ�Ǹ��� = num[i]��ǰi - 1�����ֵ�Ǹ� / ��������i���Ǹ� / ���� = bigdp[i - 1] * nums[i]����ǰֵ�Ǹ�����ǰi - 1����Сֵ�Ǹ��� = smalldp[i - 1] * nums[i]��
smalldp[i] = min(bigdp[i - 1] * nums[i], min(smalldp[i - 1] * nums[i], nums[i]));
bigdp[i] = max(smalldp[i - 1] * nums[i], max(bigdp[i - 1] * nums[i], nums[i]));


class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int len = nums.size();
		int ans = nums[0];
		//״̬���壺1.�Ե�iλ��β�����ֵ������Сֵ
		vector<int> smalldp(len, 0);//��Сֵ
		vector<int> bigdp(len, 0);//���ֵ

		smalldp[0] = bigdp[0] = nums[0];//��ʼ��

		for (int i = 1; i < len; i++){
			//ת�Ʒ���
			//��Сֵ�����������ǰi-1����Сֵ����������ǰֵ�Ǹ���smalldp[i-1]*nums[i]��ǰi-1����Сֵ�Ǹ�������i���Ǹ���nums[i]����ǰֵ�Ǹ�����ǰi-1�����ֵ������bigdp[i-1]*nums[i]��
			//���ֵҲ�����������ǰi-1�����ֵ����������ǰֵ�Ǹ��� = num[i]��ǰi-1�����ֵ�Ǹ�/��������i���Ǹ�/���� = bigdp[i-1] * nums[i]����ǰֵ�Ǹ�����ǰi-1����Сֵ�Ǹ���=smalldp[i-1]*nums[i]��
			smalldp[i] = min(bigdp[i - 1] * nums[i], min(smalldp[i - 1] * nums[i], nums[i]));
			bigdp[i] = max(smalldp[i - 1] * nums[i], max(bigdp[i - 1] * nums[i], nums[i]));
			//�����ֵ
			if (bigdp[i] > ans){
				ans = bigdp[i];
			}
		}
		return ans;

	}
};

