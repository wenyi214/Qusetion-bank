#include<iostream>
#include<string.h>
#include<string>
using namespace std;
//���ü�������˼��
int main(){
	string s1;
	while (getline(cin, s1)){
		//����һ������
		int *key = new int[26];
		//��ʼ��Ϊ0
		memset(key, 0, sizeof(int)* 26);
		//�����ַ�λ�ü�1����ͬ�ַ��ᳬ��1
		for (size_t i = 0; i<s1.size(); i++){
			key[s1[i] - '0']++;
		}
		size_t i = 0;
		for (; i<s1.size(); i++){
			//ѭ���Ҽ�¼Ϊ1��
			if (key[s1[i] - '0'] == 1){
				break;
			}
		}

		if (i<s1.size()){
			delete[] key;
			cout << s1[i] << endl;
		}
		else{
			delete[] key;
			cout << -1 << endl;
		}
	}

	return 0;

}