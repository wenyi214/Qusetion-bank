//��������������Ӱ����е��γɣ����hi��ǰ��ȵ�ǰ�߻���ȵ�����ki��
//����������Ҫ�ֿ����ۣ���������hi����ki�أ�
//�����ki����kiҲ������Ҫ��hiҲ������Ҫ����������hi����������Ƿ���Ҫ��ġ�
//hi�����մӴ�С���������Ȱ���ki��kiС����ǰ��
//��������õ�sort������дһ���ȽϺ���cmp��
//������󣬰���ki��ֵ�����Ӧ�ı�š���Ϊ��ǰ���ǰ��Ķ��ȵ�Ǯ���ߣ����뵽��Ӧ�±괦��������������ǰ��ߵ��˵ĸ�������ki�������õ�insert��
class Solution {
public:
	static bool cmp(vector<int> px, vector<int> py){//�ȽϺ���
		if (px[0] == py[0]) return px[1]<py[1];//�����ֵ��ȣ�kiС����ǰ��
		return (px[0]>py[0]);//��߸ߵ���ǰ��
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


		sort(people.begin(), people.end(), cmp);//����
		vector<vector<int>> res;
		for (int i = 0; i<people.size(); i++){
			int pos = people[i][1];
			res.insert(res.begin() + pos, people[i]);//�����Ӧ�±괦
		}

		return res;
	}
};

//����֪��vector�ײ��õ����飬������в�����ҪŲ������Ч�ʵ�
//���ǿ�����������룬�����һ��������������󷵻ء�
class Solution {
public:
	static bool cmp(vector<int> px, vector<int> py){
		if (px[0] == py[0]) return px[1]<py[1];
		return (px[0]>py[0]);
	}

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


		sort(people.begin(), people.end(), cmp);//����
		list<vector<int>> res;//����
		for (int i = 0; i<people.size(); i++){
			int pos = people[i][1];
			list<vector<int>> ::iterator it = res.begin();//������ֱ��jiapos���룬Ҫ�ҵ����
			while (pos--){
				it++;
			}
			//res.insert(res.begin()+pos,people[i]);,����res.begin+pos������
			res.insert(it, people[i]);
		}

		return vector<vector<int>>(res.begin(), res.end());
	}
};

