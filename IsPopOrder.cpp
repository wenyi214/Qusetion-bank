//ջ��ѹ���뵯��
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int len = pushV.size();
		stack<int> s;
		int j = 0;
		for (int i = 0; i<len; i++){
			//��ͬ����ջ
			s.push(pushV[i]);
			//�����ͬ����ͣ��ջ��
			while (!s.empty() && s.top() == popV[j]){
				s.pop();
				j++;
			}
		}
		return s.empty();

	}
};