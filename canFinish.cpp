
��ͼ��֪ʶ��

ͼ�Ľڵ�Ϊ�γ̡�
��ȸ�����
ָ��ýڵ�ĸ������磺C3���2��
���ȸ�����
��ǰ�ڵ�ָ���Ľڵ�ĸ������磺C5������2����
�г��ȣ�˵����ǰ�ڵ���ָ��ڵ���Ҫ����Ŀγ̡�����ȣ�˵����ǰ�ڵ㣬����Ҫ��ɵĽڵ㡣
�磺Ҫ���C9�γ���Ҫ���C1��C8��
�������������
���ǿ��Լ�¼һ���γ̵���ȸ����������Ϊ0��˵����ǰ�γ�û��Ҫ����ɵĿγ̣���ǰ�γ̿�����ɡ�
��һ������count���浱ǰϵ�G������ȸ�����
���ǿ�����һ�����б��������ɵĿγ̡�
�����һ���γ̣�������Ҫ�����Ե�ǰ�γ�Ϊ�����Ŀγ̵���ȸ�����
������Ҫ��һ������dict�����浱ǰ�γ�Ϊ���������пγ̣�����ǰ�ڵ�ָ��Ŀγ̡�
����ȸ���Ϊ0�����ǽ�����뵽�����У�˵��������ɡ�
class Solution {
private:
	vector<vector<int>> dict;//�����±��Ӧ�γ̵ĳ��ȵĿγ̣��������±��Ӧ�γ�Ϊ���������пγ�
	vector<int> count;//��ȸ�������ȵ���˼�ǣ������±�γ̶�Ӧ�γ̵���ȸ�����
	//dict[i]����Ԫ�ر����ֵ����Ӧcount�±ꡣcout��ֵ��Ӧ��Ҫ����ɿγ̵ĸ�����
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		dict.resize(numCourses);
		count.resize(numCourses, 0);
		int res = 0;//�γ���

		for (int i = 0; i<prerequisites.size(); i++){
			dict[prerequisites[i][1]].push_back(prerequisites[i][0]);//�������±��Ӧ�γ�Ϊ�����Ŀγ�
			count[prerequisites[i][0]]++;//�����������ֻ��prerequisites���л����γ�
		}
		queue<int> qe;//���������ɵĿγ̣���ȸ���Ϊ0
		for (int i = 0; i<numCourses; i++){
			if (count[i] == 0){
				qe.push(i);
			}
		}
		//˵��������Ҫ��ɵĿγ�
		while (!qe.empty()){
			//popһ��Ҫ��ɵĿγ�
			int course = qe.front();
			qe.pop();
			res++;//��ɿγ���
			//��������ɿγ�Ϊ���������пγ̵������
			//������dict[course]��
			for (int i = 0; i<dict[course].size(); i++){
				count[dict[course][i]]--;
				//�����Ϊ0��˵��������ɣ��������
				if (count[dict[course][i]] == 0){
					qe.push(dict[course][i]);
				}
			}
		}
		//�������ɿγ������Ƿ���ڣ�Ҫ�޵Ŀγ���
		return res == numCourses;

	}
};

