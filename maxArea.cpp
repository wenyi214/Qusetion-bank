

�����ⷨ��˫ѭ����ÿ�ι̶�һ�ߣ�����������������
class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;

		int side = 0;
		int maxside = 0;
		//һ�߲���������������������
		for (int i = right; i>0; i--){
			for (int j = 0; j<i; j++){
				side = (i - j)*min(height[i], height[j]);
				maxside = max(side, maxside);
			}
		}
		return maxside;

	}
};

˫ָ�뷨��
һָ��1ָ����ʼλ�ã�һָ��2ָ��ĩβ��
���ϼ�����ָ�������
������θ��£�
���������������̱ߣ�
����ָ��ֵС����ָ��ֵʱ����ָ��Ӽ�
����ָ��ֵ������ָ��ֵʱ����ָ�����
class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;

		int maxside = 0;

		while (left < right){
			//��ָ��ֵС����ָ��ֵ
			while (left<right&&height[left] <= height[right]){
				maxside = max(height[left] * (right - left), maxside);
				left++;
			}
			//��ָ��ֵС����ָ��ֵ
			while (left<right&&height[right] <= height[left]){
				maxside = max(height[right] * (right - left), maxside);
				right--;
			}
		}

		return maxside;

	}
};

