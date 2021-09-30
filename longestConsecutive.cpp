//��numsֵ���浽unordered_set�У�ȥ�أ�unordered_set��ֵʱ�临�Ӷ�O(1)
//���������еĿ�ʼֵ�������ǰֵ����С1��ֵ����unordered_set�У�˵������ʼλ�á����������ʼλ�ã�����һ��ֵ��
//Ȼ����������1��ֵ�ĸ�����
//������������
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set myset(nums.begin(), nums.end());
		int ans = 0;
		for (auto c : nums){
			if (myset.find(c - 1) != myset.end()){
				continue;
			}
			int count = 1;
			while (myset.find(++c) != myset.end()){
				count++;
			}
			if (ans < count){
				ans = count;
			}
		}
		return ans;

	}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//��numsֵ���浽set�У���ȥ���ˡ�
		//unordered_set myset(nums.begin(),nums.end());
		unordered_set myset;
		for (const int& c : nums){
			myset.insert(c);
		}
		int ans = 0;
		for (const int& c : nums){
			//��ǰֵ��ǰһ����nums�У�˵�����ǳ�ʼλ��
			if (myset.count(c - 1) == 1){
				continue;
			}
			//ǰһ������˵��ʱ��������е���ʼλ��
			int count = 1;
			//���������ֵ���Ƿ���nums��
			while (myset.count(++c) == 1){
				//�ھ͸�����1
				count++;
			}
			//������󳤶�
			if (ans < count){
				ans = count;
			}
		}
		return ans;

	}
};