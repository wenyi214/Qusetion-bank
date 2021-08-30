//����hashmap����������
//��һ������key��¼��s[j]�Ƿ���[i, j)������Ӵ��0���������Ӵ��1˵�����Ӵ��
//��Ϊ���ַ���key�ĸ������Ϊ256������ʼ��Ϊ0���ù���Ϊ1
//���key[s[j]] == 0��j++�����������ں����ǰ�ߣ����󻬶����ڵĴ�С�����ҽ�key[s[j]]++��˵���������Ӵ��
//���key[s[j]] == 1��i++������������ǰ����ǰ�ߣ���С�������ڵĴ�С�����ҽ�key[s[i]]--��˵�����������Ӵ��
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.size();
		if (len == 0){
			return 0;
		}
		if (len == 1){
			return 1;
		}
		//�����¼�Ƿ�������Ӵ���
		int *key = new int[256];
		memset(key, 0, sizeof(int)* 256);

		int i = 0;
		int j = i + 1;
		int max = 0;
		key[s[i]]++;

		while (j<len){
			//���󻬶����ڴ�С
			while (j<len&&key[s[j]] == 0){
				key[s[j]]++;
				j++;
			}
			//��¼�Ӵ��������ֵ
			if (max<j - i){
				max = j - i;
			}
			if (j == len){
				break;
			}
			//��С�������ڴ�С
			while (i<j&&key[s[j]] != 0){
				key[s[i]]--;
				i++;
			}
		}
		delete[] key;
		return max;

	}
};