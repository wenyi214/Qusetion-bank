//���ο��Ǳ�����������������ú�����������ܲ��ò������
//
//״̬���壺
//��һά����(����Ԫ��)�����浱ǰ���͵���߲�͵���õ������۸�
//һά�������壺
//�±�Ϊ0����͵��ǰ���ʱ������ֵ
//�±�Ϊ1��͵��ǰ���ʱ������ֵ
//���һά������Ƕ�̬�滮��dp���顣����˭�õ��ݹ�ʵ�֣��ݹ�Ĵ�����ʹdp����Ĳ���������ֻҪ����һ��
//Ҫ���ⴴ��һ����������ý��
////�±�0 ��ʾ��͵�����㣬�±�1��ʾ͵������
//
//
//
//ͬ����һ�����͵���涨�������ӽ��ᱨ��
//
//ת�Ʒ��̣�
//�����͵��ǰ��� ���Һ��Ӷ�����͵������͵���߲�͵��Ҫ��͵�ļ�ֵ�����ǲ�͵�ļ�ֵ����
//val2 = max(left[0], left[1]) + max(right[0], right[1]);
//���͵��ǰ��㣬���Һ��Ӷ�����͵
//val1 = root->val + left[0] + right[0];
//
//��ʼ����һ��ʼ͵���߲�͵û�н�㣬Ϊ{ 0, 0 }��
//
//
//����ֵ��
//	͵���߲�͵������ֵ
			/**
			* Definition for a binary tree node.
			* struct TreeNode {
			*     int val;
			*     TreeNode *left;
			*     TreeNode *right;
			*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
			*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
			* };
			*/
		class Solution {
		public:
			//�±�0 ��ʾ��͵�����㣬�±�1��ʾ͵������
			vector<int> robit(TreeNode* root){
				if (root == nullptr){

					return vector<int> {0, 0};
				}
				vector<int> left = robit(root->left);
				vector<int> right = robit(root->right);
				//͵,���Һ��Ӳ���͵
				int val1 = root->val + left[0] + right[0];
				//��͵,���Һ��Ӷ�����͵�����ǲ�͵(��͵���Ǹ����㣬����ǰһ�������������)������Ҫѡ����
				//����ͬ��Ľ�㣬����ͬʱ͵���涨�������ӽ��ᱨ��
				int val2 = max(left[0], left[1]) + max(right[0], right[1]);

				return vector<int> {val2, val1};
			}


			int rob(TreeNode* root) {

				vector<int> result = robit(root);
				return max(result[0], result[1]);

			}
		};

