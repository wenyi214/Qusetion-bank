

�Ե�i�У���������ʼ������������1��ֵ��
��ջ�� 84. ��״ͼ�����ľ��ε�˼·
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		int row = matrix.size();
		if (row == 0){
			return 0;
		}
		int col = matrix[0].size();
		//���浱ǰ�и���1�ĸ���
		vector<int> nums(col, 0);
		stack<int> st;
		int maxside = 0;
		for (int i = 0; i<row; i++){
			int high = 0;
			int wide = 0;
			for (int j = 0; j<col; j++){
				//���i�У���ǰ��1�ĸ���
				if (matrix[i][j] == '1'){
					nums[j]++;
				}
				else{
					nums[j] = 0;
				}
				//�����
				while (!st.empty() && nums[st.top()] > nums[j]){
					//�߶�
					high = nums[st.top()];
					st.pop();
					//���
					if (st.empty()){
						wide = j;
					}
					else{
						wide = j - st.top() - 1;
					}
					//���
					maxside = max(maxside, high*wide);
				}
				st.push(j);
			}
			while (!st.empty()){
				high = nums[st.top()];
				st.pop();

				if (st.empty()){
					wide = col;
				}
				else{
					wide = col - st.top() - 1;
				}
				maxside = max(maxside, high*wide);
			}

		}
		return maxside;

	}
};

