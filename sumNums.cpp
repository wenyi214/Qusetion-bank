#include<iostream>
using namespace std;
//��ָ Offer 64. ��1+2+��+n
//���þ�̬�����͹��캯��������n������������n�ι��캯����
//ע��oj�ж����������������һ������̬����ֵҪ�����
class Sum{
public:
	Sum(){
		_sum += _i;
		_i++;

	}
	~Sum(){
		_sum = 0;
		_i = 1;
	}
	//private:
	static int _sum;
	static int _i;

};

int Sum::_sum = 0;
int Sum::_i = 1;

class Solution {
public:
	int sumNums(int n) {
		//Sum a[n];
		Sum *a = new Sum[n];
		int res = a[0]._sum;
		//��������ֵ�����
		delete[] a;
		return res;
	}
};


int main(){
	return 0;
}