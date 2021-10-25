

�����ⷨ��
����ѭ����
���ѭ��������ǰ���飬���ѭ�����Һ�����ֵĵ�һ�����ڵ�ǰ����
������������ľ��롣
����ʱ������
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int len = temperatures.size();
		vector<int> ans(len, 0);
		for (int i = 0; i< len; i++){
			int j = i;
			//�Һ����һ�����ִ���temperatures[i]���±�
			for (; j<len; j++){
				if (temperatures[j] > temperatures[i]){
					break;
				}
			}
			if (j < len){
				ans[i] = j - i;//������Ǿ���
			}
		}
		return ans;

	}
};

��ջ��
һ�α����������ݼ�ջ
ջ���Ԫ��ά���Ķ���С��ֵ���±꣬ջ��Ԫ��ֵ��ջ��Ԫ��ֵ��
��ǰֵtemperatures[i]����ջ��Ԫ��ֵ������������������������������±������
��Ҫѭ�����������ܵ�ǰֵtemperatures[i]������ջ�������λ�õ�ֵ��
������λ�ã�����ջ��Ԫ�ر�����±�λ�á�
���������������������ջ��Ԫ��pop��
��ǰֵtemperatures[i]С��ջ��Ԫ��ֵ�����±걣�浽ջ�С�
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int len = temperatures.size();
		//ջ��Ԫ��ֵ��ջ��Ԫ��ֵ��
		stack<int> st;

		vector<int> ans(len, 0);

		for (int i = 0; i<len; i++){
			//��temperatures[i]����ջ��Ԫ��ֵ
			while (!st.empty() && temperatures[st.top()] < temperatures[i]){
				//������λ�ã�����ջ��Ԫ�ر�����±�λ�á�
				ans[st.top()] = i - st.top();
				st.pop();
			}
			//��temperatures[i]С��ջ��Ԫ��ֵ�����±걣�浽ջ�С�
			st.push(i);
		}
		return ans;

	}
};


