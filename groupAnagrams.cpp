//字母异位词，字符相同，但是顺序不同。
//将数字元素的字符串排序后，字母异位词排序后就一样了，
//可以将其保存在map中，将这个作为键值key，value用一个字符串数组，保存没排序的字符串。
//map的second就是需要的结果
class Solution {
public:
	//将strs元素字符串排序，字母异位词排序后会相同。
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, vector<string>> mymap;
		for (auto str : strs){
			//创建一个数组
			string tmp = str;
			//排序作为键值key
			sort(tmp.begin(), tmp.end());
			//将没排序的保存到map中
			mymap[tmp].push_back(str);
		}
		vector<vector<string>> ans;
		for (const auto& c : mymap){
			ans.push_back(c.second);
		}
		return ans;

	}
};