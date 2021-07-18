#include<iostream>
using namespace std;
class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 1){
			return 0;
		}
		if (n == 2){
			return 1;
		}
		if (n == 3){
			return 2;
		}
		int *dp = new int[n + 1];
		dp[0] = 0;
		//��ʼ���е��ر�ֵ�ǲ�������˺�˻������ֵ
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;

		int max = 0;
		for (int i = 4; i <= n; i++){
			//Ϊʲô��i/2����Ϊ����i/2��i-j��j��һ���ġ�
			for (int j = 1; j <= i / 2; j++){
				int tmp = dp[j] * dp[i - j];
				if (tmp>max)
					max = tmp;
			}
			dp[i] = max;
		}
		return dp[n];
	}
};
int main(){
	return 0;
}