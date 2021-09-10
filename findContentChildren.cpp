//将最大尺寸的饼干分给胃口最大的小孩。
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		//排好序
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int i = g.size() - 1;
		int j = s.size() - 1;
		int res = 0;
		while (i >= 0 && j >= 0){
			//最大的尺寸都不符合，这个人肯定不满足，直接去掉
			while (i >= 0 && s[j]<g[i]){
				i--;
			}
			if (i<0){
				break;
			}
			i--;
			j--;
			res++;

		}
		return res;

	}
};