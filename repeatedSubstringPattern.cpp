//����kmp�㷨������������ַ������ǰ��׺���ȣ��洢��next������
//��� �ַ�������len���ַ����ǰ��׺����next[len - 1]
//�� len - next[len - 1]������������ظ��Ӵ����ɣ� len - next[len - 1]����һ���Ӵ����ȣ�һ�����ڳ��ȡ�
//
//��� len%�� len - next[len - 1]�� == 0 ˵�����������ַ�����ʹ�ÿ��������ַ����ظ�����
//
//����һ�����������������ͬǰ��׺Ϊ0��û����ȵ�ǰ��׺���϶�û�з����������Ӵ�

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.size();
		vector<int> next(len, 0);
		//����next���飬j��ʾǰ׺
		int j = 0;
		//i��ʾ��׺��j��0��ʼ�����Դ�1��ʼ
		for (int i = 1; i<len; i++){
			while (j >= 1 && s[i] != s[j]){
				j = next[j - 1];
			}
			if (s[i] == s[j]){
				j++;
			}
			next[i] = j;
		}

		int x = len - next[len - 1];
		//�ǰ��׺���ȵ���0���϶��������ִ��ظ�����
		if (x == len){
			return false;
		}
		return len%x == 0;
	}
};