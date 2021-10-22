

回溯算法：
计算出扎破气球的所有情况。
利用erase和insert函数
class Solution {
private:
	int ans = 0;
	//coin硬币数总和
	void backtracing(vector<int>& nums, int coin){
		//因为会删除数组中的值，当删除完了，说明计算完毕
		if (nums.size() == 0){
			ans = max(ans, coin);
			return;
		}
		//num.size在不断变化
		for (int i = 0; i<nums.size(); i++){
			//保存当前值，回溯需要插入
			int tmp = nums[i];
			//计算扎破第i个气球的硬币数
			int mul = nums[i] * (i - 1<0 ? 1 : nums[i - 1])*(i + 1 >= nums.size() ? 1 : nums[i + 1]);
			//删除当前值
			nums.erase(nums.begin() + i);
			coin += mul;
			backtracing(nums, coin);
			//回溯
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

动态规划：
状态定义：
dp[i][j]，区间[i，j]里最大的硬币数。
转移方程：
先引爆一个气球k，分层两个区间，最大硬币数为k左边最大硬币数 + k右边最大硬币数 + 引爆第k个气球的硬币数
但是这个想法是错的，先引爆气球k，左右两个区间不是独立的，如：[3，1，5]先引爆1，3和5可以一起组合，所以左右两个区间不是独立的。
可以逆向思维，向拿出一个气球k，最后引爆，左右两个区间就是独立的了。
最大硬币数为k左边最大硬币数 + k右边最大硬币数 + 引爆第k个气球的硬币数，即dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]
为什么是nums[k] * nums[i - 1] * nums[j + 1]，i - 1，j + 1，而不是k - 1，k + 1？
因为计算dp[i][k - 1]，dp[k + 1][j]，已经将[i，j]除k以外的其余气球引爆了
i~j的长度需要从1到n计算。
class Solution {
private:
	vector<vector<int>> dp;
	int coin = 0;
	//求[i，j]硬币最大数
	int GetAns(vector<int>& nums, int i, int j){
		if (i>j){
			return 0;
		}
		//前面可能已经算过了
		if (dp[i][j] != 0){
			return dp[i][j];
		}

		for (int k = i; k <= j; k++){
			//递归求左边硬币最大数和右边硬币最大数
			int leftcoin = GetAns(nums, i, k - 1);
			int rightcoin = GetAns(nums, k + 1, j);
			//求第K个硬币数
			int mul = nums[k] * nums[i - 1] * nums[j + 1];
			coin = mul + leftcoin + rightcoin;
			//dp[i][j]是最大值
			dp[i][j] = max(dp[i][j], coin);
		}
		return dp[i][j];
	}
public:
	int maxCoins(vector<int>& nums) {
		int len = nums.size();
		dp = vector<vector<int>>(len + 2, vector<int>(len + 2, 0));
		//增加两个边界值
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		//为什么从[1,n]，因为加了两个哨兵位，在开始和结尾。
		GetAns(nums, 1, len);
		return dp[1][len];
	}
};

优化，
其实每次递归是在缩小[i，j]的长度，我们可以将[i，j]长度从小到大计算。即设置[i，j]的粒度len
不断计算每一个[i，j]的值
为什么从1开始到n，因为加了两个哨兵位
i从1到n - len + 1，j从i + len - 1
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		//[i，j]最大硬币数
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		//控制长度
		for (int len = 1; len <= n; len++){
			//范围[i，j]
			//为什么i的范围到  n - len + 1，i到j最后几个len不用求了，j越界
			//为什么要加1，len等于1时，i应该等于n
			for (int i = 1; i <= n - len + 1; i++){
				//len等于1时i = j，i<=k<=j
				int j = i + len - 1;
				for (int k = i; k <= j; k++){
					dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
				}
			}
		}
		return dp[1][n];

	}
};

