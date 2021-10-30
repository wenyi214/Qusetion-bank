

��0������ǰ�棬��2���������棬1�����Լ��ڵ�λ���ˡ�
�ҵ�˼·��
һ��ָ��p1ָ�������ʼ���Ӻ���ǰ��������0��������ǰ�治��0��λ��
ͬ��һ��ָ��ָ��ĩβ����ͷ�����������2�����������治��2��λ�á�
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		for (int i = len - 1; i>left; i--){
			if (nums[i] == 0){
				while (left < i&&nums[left] == 0){
					left++;
				}
				if (left > i){
					break;
				}
				swap(nums[left], nums[i]);
			}
		}

		for (int i = 0; i<right; i++){
			if (nums[i] == 2){
				while (right>i&&nums[right] == 2){
					right--;
				}
				if (right < i){
					break;
				}
				swap(nums[i], nums[right]);
			}
		}


	}
};

˫ָ�뷨��
һ�α���

��0��2�źþͿ�����
i�ɱ�����p1ǰ��Ϊ0��p2����Ϊ2��������p1��p2��
��nums[i]Ϊ0����nums[p1]������p1++��i++��
��nums[i]Ϊ2����nums[p2]������p2--��i�����£����ܽ�����������2������Ҫ�ж�
��nums[i]Ϊ1��ֱ�Ӹ���i��i++��
��i > p2ʱ����������������p2��0��
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int len = nums.size();

		int p1 = 0;
		int i = 0;
		int p2 = len - 1;
		//p2λ�ÿ���Ϊ0
		while (i <= p2){
			if (nums[i] == 0){
				//λ�ò�һ������
				if (i != p1){
					swap(nums[i], nums[p1]);
				}
				p1++;
				//���Ը���i�����������Ŀ϶�����0
				//i��p1��һ���ߵģ�p1λ�ÿ϶�����0
				i++;
			}
			else if (nums[i] == 2){
				swap(nums[i], nums[p2]);
				p2--;
				//��Ҫ����i�����ܽ��������Ļ���2
			}
			else{
				i++;
			}

		}

	}
};

