//��βָ�룬
//��ǰ����ż�����ҵ����ں���������������
//ע�ⲻҪԽ�磬���˳�����
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int p1 = 0;
		int p2 = nums.size() - 1;
		while (p1<p2){
			//��ż��
			while (p1<p2&&nums[p1] % 2 == 1){
				p1++;
			}
			//������
			while (p1<p2&&nums[p2] % 2 == 0){
				p2--;
			}
			//����
			swap(nums[p1], nums[p2]);

		}
		return nums;

	}
};