//现在有两个因素影响队列的形成，身高hi和前面比当前高或相等的人数ki。
//两个因素需要分开讨论，哪先讨论hi还是ki呢？
//如果按ki排序，ki也不符合要求，hi也不符合要求，所以先排hi，至少身高是符合要求的。
//hi排序按照从大到小排序，如果相等按照ki，ki小的排前面
//这里可以用到sort来排序，写一个比较函数cmp。
//排完序后，按照ki的值插入对应的编号。因为当前结点前面的都比但钱结点高，插入到对应下标处符合条件，正好前面高的人的个数等于ki。插入用到insert。
class Solution {
public:
	static bool cmp(vector<int> px, vector<int> py){//比较函数
		if (px[0] == py[0]) return px[1]<py[1];//如果两值相等，ki小的排前面
		return (px[0]>py[0]);//身高高的排前面
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


		sort(people.begin(), people.end(), cmp);//排序
		vector<vector<int>> res;
		for (int i = 0; i<people.size(); i++){
			int pos = people[i][1];
			res.insert(res.begin() + pos, people[i]);//插入对应下标处
		}

		return res;
	}
};

//我们知道vector底层用的数组，数组进行插入需要挪动数据效率低
//我们可以用链表插入，最后构造一个数组的匿名对象返回。
class Solution {
public:
	static bool cmp(vector<int> px, vector<int> py){
		if (px[0] == py[0]) return px[1]<py[1];
		return (px[0]>py[0]);
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


		sort(people.begin(), people.end(), cmp);//排序
		list<vector<int>> res;//链表
		for (int i = 0; i<people.size(); i++){
			int pos = people[i][1];
			list<vector<int>> ::iterator it = res.begin();//链表不能直接jiapos插入，要找到结点
			while (pos--){
				it++;
			}
			//res.insert(res.begin()+pos,people[i]);,不能res.begin+pos是链表
			res.insert(it, people[i]);
		}

		return vector<vector<int>>(res.begin(), res.end());
	}
};

