//��ָ Offer 43. 1��n ������ 1 ���ֵĴ���
class Solution {
public:
	int countDigitOne(int n) {
		//�ȴӸ�λ��ʼ
		long long base = 1;
		//���
		long long res = 0;
		//��¼λֵ
		int key = 0;
		while (base <= n){
			long long a = n / base;
			//base����
			long long b = n%base;
			//λֵ
			int key = a % 10;
			//baseǰ��
			a /= 10;
			//�������
			if (key == 0)
				res += a*base;
			else if (key == 1)
				res += (a*base + b + 1);
			else
				res += ((a + 1)*base);
			//��һλ
			base *= 10;
		}
		return res;


	}
};