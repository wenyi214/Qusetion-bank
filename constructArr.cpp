class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> res;
		int len = a.size();
		//a里没有元素
		if (len == 0){
			return res;
		}
		//保存上三角乘积
		int *dp1 = new int[len];
		//保存下三角乘积
		int *dp2 = new int[len];
		//左边不包含当前元素乘积
		dp1[0] = 1;
		for (int i = 1; i<len; i++){
			dp1[i] = dp1[i - 1] * a[i - 1];
		}
		//右边不包含当前元素乘积
		dp2[len - 1] = 1;
		for (int i = len - 2; i >= 0; i--){
			dp2[i] = dp2[i + 1] * a[i + 1];
		}

		//左边乘右边，就在总乘积
		for (int i = 0; i<len; i++){
			res.push_back(dp1[i] * dp2[i]);
		}
		return res;

	}
};