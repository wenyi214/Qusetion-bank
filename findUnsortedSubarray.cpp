

�ⷨһ��

�����ݷֳ����Σ�numsA��numsB��numsC��numsB������ģ���Χ[left��right]
��nums�����numsA��numsC˳�򲻻�䣬ֻ��numsB��˳���䡣
��ǰ�����ҵ�numsA��ͬ��������left���Ӻ���ǰ��numsB��������right
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		//��ʱ���飬����
		vector<int> sortnums(nums);
		sort(sortnums.begin(), sortnums.end());

		int left = 0;
		int right = nums.size() - 1;

		//ǰ������ͬ��
		while (left <= right&&nums[left] == sortnums[left]){
			left++;
		}
		//�������ͬ��
		while (left <= right&&nums[right] == sortnums[right]){
			right--;
		}

		return right - left + 1;
	}
};

��������
�����ݷֳ����Σ�numsA��numsB��numsC��numsB������ģ���Χ[left��right]
numsA������϶�ȫ��С��numsB��numsC��ֵ��
����Ӵ�С��������ȡnumsB��numC�е���Сֵmin���ҵ����һ��ֵ����min��λ�þ���left
numsC������϶�ȫ������numsB��numsA��ֵ��
�����С�����������ȡnumsA��numB�е����ֵmax���ҵ����һ��ֵС��max��λ�þ���right
ע������������
����left��right������¡�
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int len = nums.size();
		int left = -1;
		int right = -1;
		int rightmin = INT_MAX;
		int leftmax = INT_MIN;
		for (int i = 0; i<len; i++){
			//�����һ��������ֵ�������ұ�ֵ������ҵ�right
			//���ܵ��ڣ�����λ�ò�����
			if (leftmax > nums[i]){
				right = i;
			}
			//�������ֵ
			else{
				leftmax = nums[i];
			}
			//�����һ���ұߵ���Сֵ��С�����ֵ��������ҵ�left
			//���ܵ��ڣ�����λ�ò�����
			if (rightmin < nums[len - i - 1]){
				left = len - i - 1;
			}
			//������Сֵ
			else{
				rightmin = nums[len - i - 1];
			}
		}
		//����left��right�������
		return right == -1 ? 0 : right - left + 1;

	}
};

