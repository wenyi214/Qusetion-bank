#include<iostream>
using namespace std;
//剑指 Offer 64. 求1+2+…+n
//利用静态变量和构造函数，创建n个变量，调用n次构造函数。
//注意oj有多个测试用例，测下一用例静态变量值要变回来
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
		//掉析构，值变回来
		delete[] a;
		return res;
	}
};


int main(){
	return 0;
}