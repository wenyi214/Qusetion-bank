//Ҳ��ҪҪ�����ķ�Χ��
//Ҫ��������������һ��ȷ�ϵ�ǰ�����Χ(curmaccover)����ȷ���������ߵ����䡣һ����nextmaxcover������¼curmaxcover��Χ���������ߵ����Χ��
//���curmaxcover������û�е����������Ҫ��Ծһ�Σ��ٽ�nextmaxcover��ֵ��curmaxcover���������䡣���nextmaxcover�Ѿ������������λ�ã�Ҳ����Ҫ��Ծ��
//���curmaxcover������󣬲���Ҫ��Ծ��ֱ�ӷ��ء�
class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size() - 1;
		int count = 0;

		int curmaxcover = 0;//���ڵ����ֵ��Χ
		int nextmaxcover = 0;//��һ�ε����ֵ��Χ
		for (int i = 0; i<len; i++){
			nextmaxcover = max(i + nums[i], nextmaxcover);//�ռ�������������Χ
			if (i == curmaxcover){//�ߵ��������Χ

				if (curmaxcover<len){//���С��len
					count++;//��Ҫ��һ��
					curmaxcover = nextmaxcover;//��Χ����
					if (nextmaxcover >= len){//�����һ�εķ�Χ�Ѿ�����len����ͬ����
						break;
					}
				}
				else{//���ڵ����ֵ�Ѿ�����len���������
					break;
				}

			}
		}
		return count;

	}
};