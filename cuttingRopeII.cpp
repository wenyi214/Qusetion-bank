//��ָ Offer 14- II. ������ II
//����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
//ÿ�����ӵĳ��ȼ�Ϊ k[0], k[1]...k[m - 1] ������ k[0] * k[1] * ...*k[m - 1] ���ܵ����˻��Ƕ��٣�
//���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
//
//����Ҫȡģ 1e9 + 7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��

//��̰���㷨������ӣ��Լ�дpow��������pow���������ࡣ
//pow���������ÿ���������


class Solution {
public:
	int mod = 1e9 + 7;
	//������
	size_t Mypow(size_t x, int n){
		//����ֵΪsize_t
		size_t res = 1;
		size_t b = x;
		int a = n;
		while (a){
			if (a % 2){
				res = res*b%mod;
			}
			b = b*b%mod;
			a /= 2;
		}

		return res;

	}
	int cuttingRope(int n) {

		if (n == 0){
			return 0;
		}
		if (n<4){
			return n - 1;
		}
		int x = n / 3;
		int y = n % 3;
		if (y == 0){
			return Mypow(3, x) % mod;
		}
		//��1�����һ������4�����ָܷ����3��
		else if (y == 1){
			//��4*Mypow��ʽת��Ϊ sizt_t,�����������г���int��
			return 4 * Mypow(3, x - 1) % mod;
		}
		//��2
		else{
			return 2 * Mypow(3, x) % mod;
		}




	}
};