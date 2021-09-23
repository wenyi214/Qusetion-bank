//��Ϊ���ظ���Ԫ�أ������漰����Ҫȥ�صĲ�����
//ȥ�صĲ��������ȥ�صĲ������ƣ���������û���ϸ�涨������֮������λ�á������������ȥ�ء�ͬһ��Ԫ����ͬ�����������С�
//���ǰ����Ԫ����ȣ����ң�ǰ�����Ԫ��û��ʹ�ã�˵��������ǰ���Ԫ�أ�������ͬ�Ľ������ʱ���������С�
class Solution {
private:
	vector<vector<int>> result;
	vector<int> path;
	void backtracing(int len, vector<int>& nums, vector<int>& usered){
		if (path.size() == len){
			result.push_back(path);
			return;
		}
		for (int i = 0; i<len; i++){
			//���ǰһ��ûʹ�ù������һ�������һ�����������ͬ���
			if (i>0 && usered[i - 1] == 0 && nums[i] == nums[i - 1]){
				continue;
			}

			if (usered[i] == 0){
				usered[i] = 1;
				path.push_back(nums[i]);
				backtracing(len, nums, usered);
				usered[i] = 0;
				path.pop_back();
			}
		}
	}
	static bool cmp(int a, int b){
		return a<b;
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//�����򣬽���ͬ��Ԫ�ط�һ��
		sort(nums.begin(), nums.end(), cmp);
		int len = nums.size();
		//���Ԫ���Ƿ�ʹ��
		vector<int> usered;
		usered.resize(len);
		backtracing(len, nums, usered);
		return result;

	}
};