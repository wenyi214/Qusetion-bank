//�������������Ƿ��ܿ��������������
//�����԰�

class Solution {
public:
	bool isNumber(string s) {
		int i = 0;
		int len = s.size();
		//ȥ��ǰ��Ŀո�
		while (isspace(s[i])){
			i++;
		}
		int count = 0;//��¼��ĸ���
		//ֻ�е�һ���ַ�Ϊ������������Խ����ж�
		if (isdigit(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.'){
			//��һ���ַ�Ϊ������i++
			if (s[i] == '.' || s[i] == '-' || s[i] == '+'){
				//��¼.�ĸ���
				if (s[i] == '.'){
					count++;
				}
				i++;
				//+.��-.Ҳ���������ж�
				if (s[i - 1] != '.'&&s[i] == '.'){
					i++;
					count++;
				}
				//�������û�ַ��ˣ����߲������ַ���false
				if (i == len | !isdigit(s[i])){
					return false;
				}
			}

			int flag = 0;//��¼e�ĸ���
			//����Ϳ϶���������
			while (i<len){
				//����.eҲ����Ҫ��e.�����ϣ����ж�.
				//ǰ��ûe��.ʱ
				//����.����Ҫ�����Բ���i==lenʱ����false
				if (flag == 0 && s[i] == '.'&&count<1){
					i++;
					count++;
				}
				if (flag == 0 && (s[i] == 'e' || s[i] == 'E')){
					i++;

					//e�������������
					if (i == len){
						return false;
					}
					if (s[i] == ' '){
						return false;
					}
					//����ʱ���ţ����ź����������
					if (s[i] == '-' || s[i] == '+'){
						i++;
						if (i == len){
							return false;
						}
					}
					flag = 1;

				}

				//if(!isdigit(s[i])&&(flag==1||s[i]!='e'||s[i]!='E'))
				if (!isdigit(s[i])){
					//ȥ�����Ŀո�
					while (i<len&&isspace(s[i])){
						i++;
					}
					if (i == len)
						return true;
					else
						return false;
				}
				i++;
			}
			return true;

		}
		return false;






	}
};