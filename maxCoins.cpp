

�����㷨��
�����������������������
����erase��insert����
class Solution {
private:
	int ans = 0;
	//coinӲ�����ܺ�
	void backtracing(vector<int>& nums, int coin){
		//��Ϊ��ɾ�������е�ֵ����ɾ�����ˣ�˵���������
		if (nums.size() == 0){
			ans = max(ans, coin);
			return;
		}
		//num.size�ڲ��ϱ仯
		for (int i = 0; i<nums.size(); i++){
			//���浱ǰֵ��������Ҫ����
			int tmp = nums[i];
			//�������Ƶ�i�������Ӳ����
			int mul = nums[i] * (i - 1<0 ? 1 : nums[i - 1])*(i + 1 >= nums.size() ? 1 : nums[i + 1]);
			//ɾ����ǰֵ
			nums.erase(nums.begin() + i);
			coin += mul;
			backtracing(nums, coin);
			//����
			coin -= mul;
			nums.insert(nums.begin() + i, tmp);
		}
	}
public:
	int maxCoins(vector<int>& nums) {

		backtracing(nums, 0);
		return ans;

	}
};

��̬�滮��
״̬���壺
dp[i][j]������[i��j]������Ӳ������
ת�Ʒ��̣�
������һ������k���ֲ��������䣬���Ӳ����Ϊk������Ӳ���� + k�ұ����Ӳ���� + ������k�������Ӳ����
��������뷨�Ǵ�ģ�����������k�������������䲻�Ƕ����ģ��磺[3��1��5]������1��3��5����һ����ϣ����������������䲻�Ƕ����ġ�
��������˼ά�����ó�һ������k�������������������������Ƕ������ˡ�
���Ӳ����Ϊk������Ӳ���� + k�ұ����Ӳ���� + ������k�������Ӳ��������dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]
Ϊʲô��nums[k] * nums[i - 1] * nums[j + 1]��i - 1��j + 1��������k - 1��k + 1��
��Ϊ����dp[i][k - 1]��dp[k + 1][j]���Ѿ���[i��j]��k�������������������
i~j�ĳ�����Ҫ��1��n���㡣
class Solution {
private:
	vector<vector<int>> dp;
	int coin = 0;
	//��[i��j]Ӳ�������
	int GetAns(vector<int>& nums, int i, int j){
		if (i>j){
			return 0;
		}
		//ǰ������Ѿ������
		if (dp[i][j] != 0){
			return dp[i][j];
		}

		for (int k = i; k <= j; k++){
			//�ݹ������Ӳ����������ұ�Ӳ�������
			int leftcoin = GetAns(nums, i, k - 1);
			int rightcoin = GetAns(nums, k + 1, j);
			//���K��Ӳ����
			int mul = nums[k] * nums[i - 1] * nums[j + 1];
			coin = mul + leftcoin + rightcoin;
			//dp[i][j]�����ֵ
			dp[i][j] = max(dp[i][j], coin);
		}
		return dp[i][j];
	}
public:
	int maxCoins(vector<int>& nums) {
		int len = nums.size();
		dp = vector<vector<int>>(len + 2, vector<int>(len + 2, 0));
		//���������߽�ֵ
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		//Ϊʲô��[1,n]����Ϊ���������ڱ�λ���ڿ�ʼ�ͽ�β��
		GetAns(nums, 1, len);
		return dp[1][len];
	}
};

�Ż���
��ʵÿ�εݹ�������С[i��j]�ĳ��ȣ����ǿ��Խ�[i��j]���ȴ�С������㡣������[i��j]������len
���ϼ���ÿһ��[i��j]��ֵ
Ϊʲô��1��ʼ��n����Ϊ���������ڱ�λ
i��1��n - len + 1��j��i + len - 1
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		//[i��j]���Ӳ����
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		//���Ƴ���
		for (int len = 1; len <= n; len++){
			//��Χ[i��j]
			//Ϊʲôi�ķ�Χ��  n - len + 1��i��j��󼸸�len�������ˣ�jԽ��
			//ΪʲôҪ��1��len����1ʱ��iӦ�õ���n
			for (int i = 1; i <= n - len + 1; i++){
				//len����1ʱi = j��i<=k<=j
				int j = i + len - 1;
				for (int k = i; k <= j; k++){
					dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
				}
			}
		}
		return dp[1][n];

	}
};

