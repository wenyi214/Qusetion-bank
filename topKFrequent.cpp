//��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
//
//���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
//
//���� : ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//��� : ["i", "love"]
//���� : "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�
//ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		//����ĸ����ã�����ͳ�ƺô���
		map<string, int> m;
		for (auto str : words){
			m[str]++;
		}
		//����������ã��Ӵ�С�������ң�value�ַ���Ҳ���ַ�����á�
		multimap<int, string, greater<int>> mm;
		for (auto e : m){
			mm.insert(make_pair(e.second, e.first));
		}
		//����ǰk�������ǽ��
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
