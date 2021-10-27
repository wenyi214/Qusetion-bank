
用图的知识，

图的节点为课程。
入度个数：
指向该节点的个数，如：C3入度2个
出度个数：
当前节点指向别的节点的个数。如：C5出度有2个。
有出度，说明当前节点是指向节点先要上完的课程。有入度，说明当前节点，有先要完成的节点。
如：要完成C9课程先要完成C1，C8。
广度优先搜索：
我们可以记录一个课程的入度个数。当入度为0，说明当前课程没有要先完成的课程，当前课程可以完成。
用一个数组count保存当前系欸但的入度个数。
我们可以用一个队列保存可以完成的课程。
当完成一个课程，我们需要更新以当前课程为基础的课程的入度个数。
我们需要用一个数组dict来保存当前课程为基础的所有课程，即当前节点指向的课程。
当入度个数为0，我们将其放入到队列中，说明可以完成。
class Solution {
private:
	vector<vector<int>> dict;//保存下标对应课程的出度的课程，保存以下标对应课程为基础的所有课程
	vector<int> count;//入度个数，入度的意思是，保存下标课程对应课程的入度个数。
	//dict[i]数组元素保存的值，对应count下标。cout的值对应需要先完成课程的个数。
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		dict.resize(numCourses);
		count.resize(numCourses, 0);
		int res = 0;//课程数

		for (int i = 0; i<prerequisites.size(); i++){
			dict[prerequisites[i][1]].push_back(prerequisites[i][0]);//保存以下标对应课程为基础的课程
			count[prerequisites[i][0]]++;//保存入度数，只有prerequisites会有基础课程
		}
		queue<int> qe;//保存可以完成的课程，入度个数为0
		for (int i = 0; i<numCourses; i++){
			if (count[i] == 0){
				qe.push(i);
			}
		}
		//说明还有需要完成的课程
		while (!qe.empty()){
			//pop一个要完成的课程
			int course = qe.front();
			qe.pop();
			res++;//完成课程数
			//更新以完成课程为基础的所有课程的入度数
			//保存在dict[course]里
			for (int i = 0; i<dict[course].size(); i++){
				count[dict[course][i]]--;
				//入度数为0，说明可以完成，加入队列
				if (count[dict[course][i]] == 0){
					qe.push(dict[course][i]);
				}
			}
		}
		//看最后完成课程数，是否等于，要修的课程数
		return res == numCourses;

	}
};

