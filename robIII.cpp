//树形考虑遍历情况，这里必须采用后序遍历，不能采用层序遍历
//
//状态定义：
//用一维数组(两个元素)来保存当前结点偷或者不偷所得到的最大价格
//一维数组意义：
//下标为0，不偷当前结点时的最大价值
//下标为1，偷当前结点时的最大价值
//这个一维数组就是动态规划的dp数组。但是谁用到递归实现，递归的次数即使dp数组的层数。导致只要创建一个
//要另外创建一个函数来获得结果
////下标0 表示不偷这个结点，下标1表示偷这个结点
//
//
//
//同层结点一起可以偷，规定是相连接结点会报警
//
//转移方程：
//如果不偷当前结点 左右孩子都可以偷，但是偷或者不偷，要看偷的价值更大还是不偷的价值更大。
//val2 = max(left[0], left[1]) + max(right[0], right[1]);
//如果偷当前结点，左右孩子都不能偷
//val1 = root->val + left[0] + right[0];
//
//初始化：一开始偷或者不偷没有结点，为{ 0, 0 }。
//
//
//返回值：
//	偷或者不偷的最大价值
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
			//下标0 表示不偷这个结点，下标1表示偷这个结点
			vector<int> robit(TreeNode* root){
				if (root == nullptr){

					return vector<int> {0, 0};
				}
				vector<int> left = robit(root->left);
				vector<int> right = robit(root->right);
				//偷,左右孩子不能偷
				int val1 = root->val + left[0] + right[0];
				//不偷,左右孩子都可以偷或者是不偷(不偷就是隔几层，可能前一个加这个数更大)，但是要选最大的
				//可以同层的结点，可以同时偷，规定是相连接结点会报警
				int val2 = max(left[0], left[1]) + max(right[0], right[1]);

				return vector<int> {val2, val1};
			}


			int rob(TreeNode* root) {

				vector<int> result = robit(root);
				return max(result[0], result[1]);

			}
		};

