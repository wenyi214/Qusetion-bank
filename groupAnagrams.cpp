//��ĸ��λ�ʣ��ַ���ͬ������˳��ͬ��
//������Ԫ�ص��ַ����������ĸ��λ��������һ���ˣ�
//���Խ��䱣����map�У��������Ϊ��ֵkey��value��һ���ַ������飬����û������ַ�����
//map��second������Ҫ�Ľ��
class Solution {
public:
	//��strsԪ���ַ���������ĸ��λ����������ͬ��
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		unordered_map<string, vector<string>> mymap;
		for (auto str : strs){
			//����һ������
			string tmp = str;
			//������Ϊ��ֵkey
			sort(tmp.begin(), tmp.end());
			//��û����ı��浽map��
			mymap[tmp].push_back(str);
		}
		vector<vector<string>> ans;
		for (const auto& c : mymap){
			ans.push_back(c.second);
		}
		return ans;

	}
};