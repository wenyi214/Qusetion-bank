//��ȥ��ǰ��Ŀո�
//ֻ�����ֻ�����'-'��'+'�ż��㣬���򷵻�0
//�Ǹ��ż���������һ�������úͲ������Ž��һ��
//����Ǹ��ţ���ǰ��һ��(��ֹ����������)����ѭ���������ֺͣ�����һ�񸺺�
//��������ţ�Ҳ��ǰ��һ��(��ֹ����������)����ѭ���������ֺͣ�
class Solution {
public:
	int strToInt(string str) {
		int i = 0;
		//ȥ��ǰ��Ŀո�
		while (isspace(str[i])){
			i++;
		}
		long long num = 0;
		if (isdigit(str[i]) || str[i] == '-' || str[i] == '+'){
			//�����'-'��
			if (str[i] == '-'){
				//����ǰ��һ�񣬲���ѭ���������֮����--
				i++;
				//�����
				while (isdigit(str[i]) && str[i]){
					num *= 10;
					num += (str[i] - '0');
					i++;
					//��������
					if (num + INT_MIN > 0){
						return INT_MIN;
					}
				}
				//���ų�-1
				num *= -1;

			}
			else{
				//�����Ų������ţ�������һ��
				//�����'+'�ţ���ǰ��һ�񣬲���ѭ���������֮����++
				if (str[i] == '+'){
					i++;
				}

				while (str[i] && isdigit(str[i])){

					num *= 10;
					num += (str[i] - '0');
					i++;
					if (num - INT_MAX > 0){
						return INT_MAX;
					}
				}

			}

		}

		return num;
	}
};