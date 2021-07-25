class Solution {
public:
	//归并排序
	void MergeSort(vector<int>& nums, int left, int right, vector<int>& temp, int& count){
		//终止条件
		if (left >= right){
			return;
		}
		//计算中间值
		int mid = left + (right - left) / 2;
		//递归
		MergeSort(nums, left, mid, temp, count);
		MergeSort(nums, mid + 1, right, temp, count);
		//归并操作
		int begin1 = left;
		int end1 = mid;
		int begin2 = mid + 1;
		int end2 = right;
		int i = left;
		//比较后放将有序数放到临时数组中
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
			//如果只剩下左边的数，上面已经将这种情况计算了
			//count+=(end1-begin1+1);
			temp[i++] = nums[begin1++];
		}
		while (begin2 <= end2){
			temp[i++] = nums[begin2++];
		}
		//放回原来数组
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