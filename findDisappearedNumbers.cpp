直接用数组记录数显的数
再在其中找未出现的数。实现复杂度O(n)，空间复杂度O(n)
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int len = nums.size();
		//记录[1,n]里的数是否出现
		vector<int> numsCount(len + 1, 0);
		vector<int> ans;
		for (int i = 0; i<len; i++){
			numsCount[nums[i]]++;
		}

		for (int i = 1; i <= len; i++){
			//没有出现，加到返回数组中
			if (numsCount[i] == 0){
				ans.push_back(i);
			}
		}
		return ans;

	}
};

优化：
时间复杂度O(n)，空间复杂度O(1)
在原数组nums上修改。
要确认[1，n]没出现的数。用一个比n大的数来表述该数出现了。
遍历 nums，每遇到一个数 x，就让nums[x - 1 增加 n。由于nums 中所有数均在[1, n] 中，增加以后，这些数必然大于 n。最后我们遍历 nums，若 nums[i] 未大于 n，就说明没有遇到过数，这样我们就找到了缺失的数字。
为什么将x - 1加上n，因为nums数组下标从[0，n - 1]，就对应了所有的下标。
为什么加上n，因为前面的数可能会对应后面下标，将后面的数修改了。后面会遍历到，加n，对n求余还是之前的值。不影响
如果缺了某一值，对应值下标减1处不会加n
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;
		for (auto& x : nums){
			int c = x - 1 % n;//放到x-1处，所以要x-1，余n是可能会改变后面的数，余n还是原来的值
			nums[c] += n;//将x-1处的值加n，如果缺了某一值，对应值下标减1处不会加n
		}

		for (int i = 0; i<n; i++){
			if (nums[i] <= n){//如果不缺肯定都大于n，小于n的肯定是缺的
				ans.push_back(i + 1);//数组下标[0,n-1]，所以要加1.
			}
		}
		return ans;
	}
};

