//

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();

		map<int, int> m;
		for (auto e : nums){
			m[e]++;
		}
		int res = 0;
		for (auto e : m){
			if (e.second > len / 2){
				res = e.first;
				break;
			}
		}
		return res;

	}
};

//�ռ临�Ӷ�ΪO(1)
//������ȡ�м�ֵ��ʱ�临�Ӷȸߡ����š�
int Sort(int *num, int left, int right){
	int key = num[left];
	while (left < right){
		while (left < right&&num[right] >= key){
			right--;
		}
		num[left] = num[right];
		while (left < right&&num[left] <= key){
			left++;
		}
		num[right] = num[left];
	}
	num[right] = key;
	return right;
}


void QuickSort(int *num, int left, int right){
	if (left >= right){
		return;
	}

	int k = Sort(num, left, right);
	QuickSort(num, left, k - 1);
	QuickSort(num, k + 1, right);

}