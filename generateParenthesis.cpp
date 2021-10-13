��������¼�������Ÿ���
�ȷ������ţ�����������ʣ��������������ʣ����ʱ���ſ��Է������ţ���Ȼ˳�򲻶ԡ�
class Solution {
private:
	vector<string> res;
	string path;
	void backtracing(int left, int right){//left��¼����������right��¼��������

		if (left == 0 && right == 0){//�������Ŷ�������
			res.push_back(path);
			return;
		}
		if (left>0){//���������ȷ�������
			path += '(';
			left--;
			backtracing(left, right);
			path.pop_back();
			left++;
		}
		if (left < right){//�������������������������Է�һ��������
			path += ")";
			right--;
			backtracing(left, right);
			right++;
			path.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		backtracing(n, n);
		return res;
	}
};