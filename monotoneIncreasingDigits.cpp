//�ҵ�С�ڵ���n�ҵ�λ����λ�����������������
//������������n��ʼ�ң�ÿ��n--����֤���������ֻ��Ҫ��λ����λ����������
//дһ�������жϣ��ֳ�ÿһλ����λ���λ�Ƚϡ�
class Solution {
public:
	bool check(int num){
		//��λ
		int max = num % 10;
		while (num){
			num /= 10;
			//��λ
			int m = num % 10;
			//�Ƚϣ�maxΪ��һ�εĸ�λ��������һ�εĵ�λ
			if (max >= m){
				max = m;
			}
			else{
				return false;
			}

		}
		return true;
	}
	//�����㷨
	int monotoneIncreasingDigits(int n) {
		int i = n;
		for (; i >= 0; i--){
			if (check(i)){
				break;
			}
		}
		return i;

	}
};

//̰�ģ�
//������תΪ�ַ��������str[i - 1]>str[i]��str[i - 1]--��str[i - 1]ǰ�����������д��9��
//���磺876��С�ڵ���876����������Ϊ 876->869->799
//������Ҫ�����������������������ұ�����ǰ�������Ȼ���ܱȺ��������
class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		string str = to_string(n);
		int len = str.size();
		//��¼Ҫ��9�Ŀ�ʼλ��
		int index = len;
		for (int i = len - 1; i>0; i--){
			if (str[i - 1]>str[i]){
				//�����ַ�ʱ�����ģ��ַ���1�൱�����ּ�1
				str[i - 1]--;
				index = i;
			}
		}
		//��1λ�õĵ�λ�������ֶ�������Ϊ9
		for (int i = index; i<len; i++){
			str[i] = '9';
		}

		int x = atoi(str.c_str());
		return x;
		//return stoi(str);

	}
};