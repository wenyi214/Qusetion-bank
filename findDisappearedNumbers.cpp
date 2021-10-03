ֱ���������¼���Ե���
����������δ���ֵ�����ʵ�ָ��Ӷ�O(n)���ռ临�Ӷ�O(n)
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int len = nums.size();
		//��¼[1,n]������Ƿ����
		vector<int> numsCount(len + 1, 0);
		vector<int> ans;
		for (int i = 0; i<len; i++){
			numsCount[nums[i]]++;
		}

		for (int i = 1; i <= len; i++){
			//û�г��֣��ӵ�����������
			if (numsCount[i] == 0){
				ans.push_back(i);
			}
		}
		return ans;

	}
};

�Ż���
ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
��ԭ����nums���޸ġ�
Ҫȷ��[1��n]û���ֵ�������һ����n��������������������ˡ�
���� nums��ÿ����һ���� x������nums[x - 1 ���� n������nums ������������[1, n] �У������Ժ���Щ����Ȼ���� n��������Ǳ��� nums���� nums[i] δ���� n����˵��û�������������������Ǿ��ҵ���ȱʧ�����֡�
Ϊʲô��x - 1����n����Ϊnums�����±��[0��n - 1]���Ͷ�Ӧ�����е��±ꡣ
Ϊʲô����n����Ϊǰ��������ܻ��Ӧ�����±꣬����������޸��ˡ���������������n����n���໹��֮ǰ��ֵ����Ӱ��
���ȱ��ĳһֵ����Ӧֵ�±��1�������n
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		for (auto& x : nums){
			int c = x - 1 % n;//�ŵ�x-1��������Ҫx-1����n�ǿ��ܻ�ı�����������n����ԭ����ֵ
			nums[c] += n;//��x-1����ֵ��n�����ȱ��ĳһֵ����Ӧֵ�±��1�������n
		}

		for (int i = 0; i<n; i++){
			if (nums[i] <= n){//�����ȱ�϶�������n��С��n�Ŀ϶���ȱ��
				ans.push_back(i + 1);//�����±�[0,n-1]������Ҫ��1.
			}
		}
		return ans;
	}
};

