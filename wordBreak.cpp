//��̬�滮��
//��wordDict���ʱ��浽set��ϣ���У�����Ч�ʸ�
//״̬���壺
//dp[i]��ǰi���ַ��Ƿ��ܲ��
//ת�Ʒ��̣�
//dp[i]״̬������ǰi���ַ���������֡�j��0~i����ǰj��dp[j]�Ƿ��ܲ�� && j��i�Ӵ��Ƿ��ܲ��
//��ʼ����
//dp[0] = true
//����ֵ��
//dp[s.size()]
	class Solution {
	public:
		//��̬�滮
		bool wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string> myset;
			for (auto c : wordDict){
				myset.insert(c);
			}
			int len = s.size();
			vector<bool> dp(len + 1, false);
			dp[0] = true;//��ʼ����û���ַ������Բ��
			for (int i = 1; i <= s.size(); i++){
				//���
				for (int j = 0; j<i; j++){
					//���Ƿ��ܲ�֣���ǰj��dp[j]�Ƿ��ܲ�� && j��i�Ӵ��Ƿ��ܲ��
					//ע��ʹ��substr�Ӵ�
					if (dp[j] && myset.find(s.substr(j, i - j)) != myset.end()){
						dp[i] = true;
						break;
					}
				}
			}
			return dp[len];


		}
	};