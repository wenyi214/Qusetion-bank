//如果找到之前遍历过的所有字⺟的最远边界，说明这个边界就是分割点了。此时前⾯出现过所有字⺟，最远也就到这个边界了。
//1.先收集每个字符在字符串中的最大范围
//2.找到前面字符的最大范围，如果和现在现在的下标相等，说明找到了分割点。
class Solution {
public:
	vector<int> partitionLabels(string s) {
		//看字符的最大范围，是否和当前位置相等
		int *cover = new int[26];
		int len = s.size();
		//收集字符在字符串s中的最大范围
		for (int i = 0; i<len; i++){
			cover[s[i] - 'a'] = i;
		}
		vector<int> result;
		int end = 0;
		int start = 0;
		//如果前面的字符的最大范围和当前下标相等，说明到了分割点
		for (int i = 0; i<len; i++){
			end = max(end, cover[s[i] - 'a']);//找到现在为止的最远边界
			if (i == end){
				result.push_back(end - start + 1);
				start = end + 1;
			}
		}

		return result;

	}
};