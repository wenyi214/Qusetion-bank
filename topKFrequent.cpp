//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
//
//输入 : ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出 : ["i", "love"]
//解析 : "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//注意，按字母顺序 "i" 在 "love" 之前。

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//按字母排序好，并且统计好次数
		map<string, int> m;
		for (auto str : words){
			m[str]++;
		}
		//按次数排序好（从大到小），并且，value字符串也按字符排序好。
		multimap<int, string, greater<int>> mm;
		for (auto e : m){
			mm.insert(make_pair(e.second, e.first));
		}
		//遍历前k个，就是结果
		vector<string> res;
		for (auto e : mm){
			if (k == 0){
				break;
			}
			res.push_back(e.second);
			k--;
		}

		return res;

	}
};
