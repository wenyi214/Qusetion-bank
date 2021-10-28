

�����������ţ��ҳ����п��ܵ��Ӵ�������Ч���ŵ��Ӵ�������������
���û����㷨��
һ�����ž�ֻ��ȡ�벻ȡ����ѡ����ѡ��ȡ����ѡ��ȡ���������������һ�顣
��һ���������������ŵĸ������������꣬�����ŵ���0��˵���Ӵ�������Ч����Ϊ0 ˵����Ч��
��һ��map������������Ч�����Ӵ�����ֵΪ�Ӵ����ȣ�Ҫ�õ�ɾ��������С����Ч���ţ�˵���Ӵ�������Ҫ��ġ�
class Solution {
public:
	vector<string> ans;
	int visitedLeft = 0;
	map<int, set<string>> mm;
	void dfs(string s, int idx, string& t) {
		if (idx == s.size()) {
			if (0 == visitedLeft) {
				mm[t.size()].insert(t);
			}
			return;
		}

		if (s[idx] == '(') {
			//ѡ��ɾ��
			dfs(s, idx + 1, t);

			//ѡ����
			t.push_back('(');
			visitedLeft++;
			dfs(s, idx + 1, t);
			visitedLeft--;
			t.pop_back();
		}
		else if (s[idx] == ')') {
			//ѡ��ɾ��
			dfs(s, idx + 1, t);

			//���֮ǰ�м�¼�����Ųſ��ܱ���������
			if (visitedLeft != 0) {
				t.push_back(')');
				visitedLeft--;
				dfs(s, idx + 1, t);
				visitedLeft++;
				t.pop_back();
			}
		}
		else {
			//�����ŵ��ַ� ֱ�Ӵ���
			t.push_back(s[idx]);
			dfs(s, idx + 1, t);
			t.pop_back();
		}

	}

	vector<string> removeInvalidParentheses(string s) {
		string t;
		dfs(s, 0, t);

		auto tt = mm.rbegin();
		for (auto & e : tt->second) {
			ans.push_back(e);
		}

		return ans;
	}
};

������ʱ�ˣ���Ҫ��֦
��������������ͬʱ����ֻȡһ������ʱ��ȡ��һ�����ź͵ڶ������ţ���ʵ�õ��Ľ�����кܶ���ͬ��ֵ�����˺ܶ��ظ��Ĳ�����

������Ҫ�ڱ������ź�ɾ������ǰ���ȼ�����ж�����������
��ȷ��һ���Ա�������ɾ���������ţ�
��һ�εݹ�����֮����������ź��濪ʼ�Ҿͺ��ˡ�
class Solution {
private:
	//set<string> st;
	int leftnum = 0;//ʣ��"("�ĸ������������Ƿ�ƥ��,Ϊ0˵��ƥ��
	map<int, set<string>> mm;//map��ֵ����Ч���ų��ȣ�set��Ϊ��ȥ�ء�
	void Dfs(const string& s, int index, string& t){
		//������������Ч�������Ӵ�
		if (index == s.size()){
			//���Ŷ�ƥ��
			if (leftnum == 0){
				mm[t.size()].insert(t);
			}
			return;
		}
		//�������ţ����ַ����棬��ΪҪɾ��������С���ַ���ɾ����������һ��
		if (s[index] != '(' && s[index] != ')'){
			t += s[index];
			Dfs(s, index + 1, t);
			t.pop_back();
			//����ֱ�ӷ���
			return;
		}
		//�Ҵӵ�ǰλ�ÿ�ʼ��ͬ���ŵ�����
		int k = 0;
		for (int i = index; i<s.size(); i++){
			if (s[index] == s[i]){
				k++;
			}
			else{
				break;
			}
		}
		//������
		if (s[index] == '('){
			//ȷ�ϱ�����ͬK���ַ��еĶ�����
			for (int i = 0; i <= k; i++){
				//i=k��ȫ������i=0������������i=1����һ��...
				for (int j = 0; j<i; j++){
					t += '(';
					leftnum++;
				}
				//��һ�δ��������ź��濪ʼ�Ҿͺ���
				Dfs(s, index + k, t);
				//����
				for (int j = 0; j<i; j++){
					t.pop_back();
					leftnum--;
				}
			}
		}
		else{
			//")"
			for (int i = 0; i <= k; i++){
				//��Ҫʣ��������Ŵ��������ŵ��������ſ��Լ���������
				//�ж���������ſ϶���ƥ�䡣
				if (i <= leftnum){
					for (int j = 0; j< i; j++){
						t += ')';
						leftnum--;
					}
					Dfs(s, index + k, t);
					for (int j = 0; j<i; j++){
						t.pop_back();
						leftnum++;
					}

				}
			}
		}
	}

public:
	vector<string> removeInvalidParentheses(string s) {
		string t;
		Dfs(s, 0, t);
		vector<string> ans;
		//��Ҫɾ��������С����Ҫ��Ч���ų����
		//map��������ǳ�����ģ����Դ����һ����ʼ
		auto it = mm.rbegin();
		for (auto ch : it->second){
			ans.push_back(ch);
		}
		return ans;
	}
};

