//这道题⽬有⼏个难点：
//1. ⼀个⾏程中，如果航班处理不好容易变成⼀个圈，成为死循环
//2. 有多种解法，字⺟序靠前排在前⾯，让很多同学望⽽退步，如何该记录映射关系呢 ？
//3. 使⽤回溯法（也可以说深搜） 的话，那么终⽌条件是什么呢？
//4. 搜索的过程中，如何遍历⼀个机场所对应的所有机场。
//
//1. ⼀个⾏程中，如果航班处理不好容易变成⼀个圈，成为死循环 ?
//为什么是这样？比如["JFK"，"NRT"]，["NRT"，"JFK"]。起始只有两个航班，两个航班起点和重点是相反的，这样会形成一个循环，最终递归返回导致错误的结果。
//所以我们每次用完一个航班就需要删除这个航班或者标记。
//2..如何确定映射关系？
//这里要确定起始位置和终止位置的映射关系，并且出现的起始位置会有重叠。
//如果直接用multimap<string，string>，或者unordered_map<string，multiset<string>> 在删除时，会导致迭代器失效。(multimap<起始位置，终止位置>，unordered_map<起始位置，multiset<终止位置>>
//我们可以使用unordered_map<string，map<string，int>>，含义：unordered_map<起始位置，map<终止位置，起始位置相同的航班数>>，用航班个数记录是否还能用该航班，不用做删除操作。
//3. 终止条件
//每次都会要走一个航班，但是起始还有一个"JFK"，所以当收集结果个数等于航班数加1，返回。
//4. 通过回溯法来遍历各机场
//递归参数
//ticketsnum表示航班数
//
//vector<string> result;//保持结果
////返回值bool，因为我们只需要找一条线
//bool backtracing(unordered_map<string, map<string, int>>& key, int ticketsnum)
//返回值为bool，由题意，至少存在一种合理行程，我们只要找到该行程再一直返回就好了。
//result和key都需要初始化：
//由题意，行程由"JKF"出发。
//key记录内一个航班起始和终止，并且相同起点，的航班数。
//递归终止条件
//每次都会要走一个航班，但是起始还有一个"JFK"，所以当收集结果个数等于航班数加1，返回。
//if (result.size() == ticketsnum + 1){
//	return true;
//	单层递归逻辑
//	这里有一个很隐晦的条件，通过result里的值作为起点再key中找终点。得到c。
//	再判断该位置是否还能用。
//	注意：pairstring⾥要有const，因为map中的<key，value>的key是不可修改的，所以是 pair<const string, int> 。
	class Solution {
		vector<string> result;
		//返回值bool，因为我们只需要找一条线
		bool backtracing(unordered_map<string, map<string, int>>& key, int ticketsnum){
			if (result.size() == ticketsnum + 1){
				return true;
			}
			//key[result[result.size()-1]是通过起点找终点，
			for (pair<const string, int>& c : key[result[result.size() - 1]]){
				//看是否还能用
				if (c.second>0){
					c.second--;
					result.push_back(c.first);
					if (backtracing(key, ticketsnum) == true){
						return true;
					}
					c.second++;
					result.pop_back();
				}
			}
			return false;
		}

	public:
		vector<string> findItinerary(vector<vector<string>>& tickets) {
			//key<起始位置，<终止位置，航班次数>>
			unordered_map<string, map<string, int>> key;
			int ticketsnum = tickets.size();
			for (int i = 0; i<ticketsnum; i++){
				key[tickets[i][0]][tickets[i][1]]++;
			}
			result.push_back("JFK");
			backtracing(key, ticketsnum);
			return result;



		}
	};