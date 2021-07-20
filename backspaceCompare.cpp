#include<iostream>
using namespace std;
class Solution {
public:
	bool backspaceCompare(string s, string t) {
		//��¼�˸���ĸ���
		int sindex = 0;
		int tindex = 0;
		//�Ӻ��濪ʼ����
		int i = s.size() - 1;
		int j = t.size() - 1;
		while (1){
			//ȥ��s�˸����������ֵ
			while (i >= 0){
				//������˸������¼��1�����λ�û����
				if (s[i] == '#'){
					sindex++;

				}
				//�����˸������¼��1��
				else{
					if (sindex>0){
						sindex--;
					}
					//��������˸�����ң���¼Ϊ0 ���˳��Ƚ�
					else{
						break;
					}
				}

				i--;
			}
			//ȥ��t�˸����������ֵ
			while (j >= 0){
				if (t[j] == '#'){
					tindex++;
				}
				else{
					if (tindex>0){
						tindex--;
					}
					else{
						break;
					}
				}

				j--;
			}
			//�����һ�������ַ��Ƚϣ�����һ��û���ַ��ˡ�����false
			if ((i<0 && j >= 0) || (i >= 0 && j<0)){
				return false;
			}
			//���������û�ַ��Ƚϣ��˳���������
			if (i<0 && j<0){
				break;
			}
			//ֵ����ȷ��ؼ�
			if (s[i] != t[j]){
				return false;
			}
			//��ȣ�˵������ֵ���ȽϺ��������
			i--, j--;
		}
		return true;

	}
};

int main(){
	return 0;
}