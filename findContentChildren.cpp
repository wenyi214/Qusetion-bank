//�����ߴ�ı��ɷָ�θ������С����
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		//�ź���
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		int i = g.size() - 1;
		int j = s.size() - 1;
		int res = 0;
		while (i >= 0 && j >= 0){
			//���ĳߴ綼�����ϣ�����˿϶������㣬ֱ��ȥ��
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