//有一种特殊情况，如果结点为空，当前应该是哪种状态：如果设置为没有被覆盖，叶子结点就会是摄像头，如果设为摄像头，叶子结点就是被覆盖，父节点就不会设为摄像头，所以空结点为已覆盖状态。
//此时有4种情况
//1.如果左右子节点都是被覆盖，当前结点为没有被覆盖
//2.如果左右子节点有一个没有被覆盖，当前结点因该时摄像头，摄像头数加1
//3.如果左右子节点有一个是摄像头，当前结点为被覆盖
//4.有一种情况，根节点为没有覆盖，此时左右子节点是被覆盖，此时将根节点设为摄像头


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
private:
	int result = 0;
	int pastorder(TreeNode* root){
		if (root == nullptr){
			return 0;
		}

		int left = pastorder(root->left);
		int right = pastorder(root->right);
		//左右子节点都是被覆盖
		if (left == 0 && right == 0){
			return 2;
		}
		//这个要放在左右子节点有一个是摄像头前面
		//有一种情况，left==1，right==0的情况，要设摄像头就被忽略了
		//左右子节点有一个未被覆盖
		if (left == 2 || right == 2){
			result++;
			return 1;

		}
		//左右子节点有一个是摄像头
		if (left == 1 || right == 1){
			return 0;
		}

		return -1;
	}

public:
	int minCameraCover(TreeNode* root) {


		//如果根节点为空
		if (pastorder(root) == 2){
			result++;
		}
		return result;


	}
};