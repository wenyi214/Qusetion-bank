//暴力解法：连续子集
//两层循环，一层循环控制从哪一个开始。
//第二层循环，求子集和，注意是从第一层循环开始，加到0，
//为什么不从0开始，如果从0开始，求的都是从0开始的子集。
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int count = 0;

		for (int start = 0; start < nums.size(); start++){
			int sum = 0;
			//为什么不从0开始，如果从0开始，每一个子集都是从0开始
			//不是需要所有子集从0开始
			for (int end = start; end >= 0; end--){
				sum += nums[end];
				if (sum == k){
					++count;
				}
			}
		}
		return count;

	}
};

//利用哈希表做优化 + 前缀和
//子集和等于k。
//子集区间可以是[j， i]。设pre[i]为0~i的和，pre[j - 1]为0~i - 1d的和。
//所以[j，i]子集和等于  pre[i] - pre[j - 1] ，
//想让子集和等于k，有  pre[i] - pre[j - 1] = k ——>   pre[j - 1] = pre[i] - k。
//所以转化为  求区间[0，i]中字节和等于 pre[i] - k的个数和。
//用一个哈希表记录。
//键值为字节和，value为[0，i]子集和为key出现的个数。
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int count = 0;
		//一开始和为0
		m[0]++;
		int sum = 0;
		for (auto& a : nums){
			//前缀和，只需要在之前的基础上，加上nums[i]
			sum += a;
			//找[0,i]前缀和等于sum-k的个数，个数记在map的m.second中
			if (m.find(sum - k) != m.end()){
				count += m[sum - k];
			}
			//将前缀和加入map或者存在的话，将个数加1
			m[sum]++;
		}
		return count;

	}
};