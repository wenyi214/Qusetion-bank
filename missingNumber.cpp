//0~n - 1�������������У�Ӧ�������������±��Ӧ��
//�ö��ֲ��ң��ҵ��±겻��Ӧ�ġ�
//����ֵ���±����ʱ��˵������ȵ����ں��档
//����ֵ���±겻���ʱ��˵�����ܾ��ǵ�ǰ�����������ǰ�档
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int left = 0;
		int right = nums.size();

		while (left<right){
			int mid = left + (right - left) / 2;
			/ ���ʱ��˵���ں���
			if (nums[mid] == mid){
				left = mid + 1;
			}
			//����ʱ˵���ǵ�ǰ��������ߣ���ǰ�档
			//������right=nums.size��ȡ����������ѭ���˳�����û�е���
			//right����ֱ��ȡmid
			else{
				right = mid;
			}
		}
		return right;

	}
};