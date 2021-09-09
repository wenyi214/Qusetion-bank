class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> res;
		int len = a.size();
		//a��û��Ԫ��
		if (len == 0){
			return res;
		}
		//���������ǳ˻�
		int *dp1 = new int[len];
		//���������ǳ˻�
		int *dp2 = new int[len];
		//��߲�������ǰԪ�س˻�
		dp1[0] = 1;
		for (int i = 1; i<len; i++){
			dp1[i] = dp1[i - 1] * a[i - 1];
		}
		//�ұ߲�������ǰԪ�س˻�
		dp2[len - 1] = 1;
		for (int i = len - 2; i >= 0; i--){
			dp2[i] = dp2[i + 1] * a[i + 1];
		}

		//��߳��ұߣ������ܳ˻�
		for (int i = 0; i<len; i++){
			res.push_back(dp1[i] * dp2[i]);
		}
		return res;

	}
};