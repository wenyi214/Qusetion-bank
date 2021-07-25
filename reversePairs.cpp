class Solution {
public:
	//�鲢����
	void MergeSort(vector<int>& nums, int left, int right, vector<int>& temp, int& count){
		//��ֹ����
		if (left >= right){
			return;
		}
		//�����м�ֵ
		int mid = left + (right - left) / 2;
		//�ݹ�
		MergeSort(nums, left, mid, temp, count);
		MergeSort(nums, mid + 1, right, temp, count);
		//�鲢����
		int begin1 = left;
		int end1 = mid;
		int begin2 = mid + 1;
		int end2 = right;
		int i = left;
		//�ȽϺ�Ž��������ŵ���ʱ������
		while (begin1 <= end1&&begin2 <= end2){
			if (nums[begin1]>nums[begin2]){
				count += (end1 - begin1 + 1);
				temp[i++] = nums[begin2++];
			}
			else{

				temp[i++] = nums[begin1++];
			}
		}
		while (begin1 <= end1){
			//���ֻʣ����ߵ����������Ѿ����������������
			//count+=(end1-begin1+1);
			temp[i++] = nums[begin1++];
		}
		while (begin2 <= end2){
			temp[i++] = nums[begin2++];
		}
		//�Ż�ԭ������
		for (int j = left; j <= right; j++){
			nums[j] = temp[j];
		}

	}


	int reversePairs(vector<int>& nums) {

		size_t len = nums.size();
		if (len == 0){
			return 0;
		}
		vector<int> temp;
		temp.resize(len);
		int count = 0;
		MergeSort(nums, 0, len - 1, temp, count);
		return count;
	}
};