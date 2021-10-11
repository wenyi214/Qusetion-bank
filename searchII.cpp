Ҫ����log(N)ʱ�䷶Χ���ҳ�target�±�

�ҿ��Խ�����ֳ����Σ�������һ�ο϶�������ģ�һ��������
�����һ�Σ����ǿ����ö��ֲ��ң�����target���±�
�����һ�Σ����Ǽ����ֳ����Σ�һ������һ������ѭ����
��ηֳ����Σ�Ҳ�ö��ֲ��ҡ�
[left, right]������ģ�[l, r]������ġ�
class Solution {
private:
	int FindNumber(vector<int>& nums, int left, int right, int target){
		while (left <= right){
			int mid = left + (right - left) / 2;
			if (nums[mid] < target){
				left = mid + 1;
			}
			else if (nums[mid] > target){
				right = mid - 1;
			}
			else{
				return mid;
			}
		}
		return -1;
	}
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		if (l > r){
			return -1;
		}
		int res = 0;
		int mid = 0;
		//[left,right]�������
		int left = 0;
		int right = 0;
		//�����֣�[l,r]������ģ��ö��֣��ֳ�һ������
		//���������������
		while (l <= r){
			mid = l + (r - l) % 2;
			//�ұ�����
			if (nums[mid] < nums[l]){
				//[left,right]�������
				left = mid;
				right = r;
				//������������
				r = mid - 1;
			}
			//�������
			else if (nums[mid] >= nums[l]){

				left = l;
				right = mid;
				//������������
				l = mid + 1;
			}
			else{

			}
			//������������
			res = FindNumber(nums, left, right, target);
			//�ҵ�
			if (res != -1){
				break;
			}

		}
		return res;

	}
};