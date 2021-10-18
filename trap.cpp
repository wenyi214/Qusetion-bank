

������ǵ�ǰλ�ÿ��Ի�ˮ��������ǰ�п��Խ�ˮ������

��Ҫ˼·�������ǰλ�ã���ߵ����ֵ���ұߵ����ֵ�����еĽ�Сֵm��������ڵ�ǰֵ����ǰ���ܻ���ˮ��Ϊ m - height[i]
������ֵ���ұ����ֵ�е���Сֵ�����ˮ����
��̬�滮��
״̬���壺
�������飺left[i]��iλ��ߵ����ֵ��right[i]��iλ�ұߵ����ֵ��
ת�Ʒ��̣�
��ǰλ�õĻ�ˮ������ߵ����ֵ���ұߵ����ֵ�����еĽ�Сֵm�����С�ڵ�ǰֵ����ǰ���ܻ���ˮ��Ϊ m - height[i]
��ʼ����
��iλ������ֵ���������ұ���������������ֵ��
��iλ�ұ����ֵ��������������������ұ����ֵ��
����ֵ��
��ˮ���ĺ͡�
class Solution {
public:
	//��̬�滮
	int trap(vector<int>& height) {
		int len = height.size();

		int leftmax = 0;
		int rightmax = 0;

		vector<int> left(len, 0);//�����iλ������ֵ
		vector<int> right(len, 0);//�����iλ�ұ����ֵ
		//�������ұ�������iλ������ֵ
		for (int i = 1; i<len; i++){
			leftmax = max(leftmax, height[i - 1]);
			left[i] = leftmax;
		}
		//���������������jλ�ұߵ����ֵ
		for (int j = len - 2; j >= 0; j--){
			rightmax = max(rightmax, height[j + 1]);
			right[j] = rightmax;
		}
		int ans = 0;
		for (int i = 1; i<len; i++){
			//�����������ֵ��Ľ�Сֵ
			int tmp = min(left[i], right[i]);
			if (tmp > height[i]){
				ans += tmp - height[i];//��ǰ�еĻ�ˮ��
			}
		}

		return ans;
	}
};

˫ָ�뷨��
һ��ָ��1ָ���ʼ��һ��ָ��2ָ��ĩβ��
ָ��1��ֵ��ָ��2�е�ֵС���Ǹ����ߣ���˼Ҳ���������߽�Сֵ����Ǳ߽硣
������߻����ұߵ����ֵ�������㵱ǰ�е�ˮ����
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		int left = 0;
		int right = len - 1;
		int leftmax = 0;
		int rightmax = 0;
		int ans = 0;
		while (left < right){
			//��ָ��ֵС����ָ��ֵʱ������˵����ߵͣ�����©ˮ
			while (left<right&&height[left] <= height[right]){
				//�ܽ���ѭ��˵����������ֵС���ұ����ֵ
				leftmax = max(leftmax, height[left]);
				//������ֵ����ǰ�е�ֵ
				if (height[left] < leftmax){
					ans += (leftmax - height[left]);
				}
				left++;
			}
			//��ָ��ֵС����ָ��ֵʱ������˵���ұߵͣ�����©ˮ
			while (left<right&&height[left] >= height[right]){
				rightmax = max(height[right], rightmax);
				if (height[right] < rightmax){
					ans += (rightmax - height[right]);
				}
				right--;
			}

		}
		return ans;

	}
};

