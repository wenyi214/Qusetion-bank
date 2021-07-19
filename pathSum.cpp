#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void backtracking(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int target, int sum){
		//�ݹ鷵������
		if (root == nullptr){
			return;
		}
		//�ռ�ֵ
		path.push_back(root->val);
		sum += root->val;
		//�ռ����
		if (root->left == nullptr&&root->right == nullptr&&sum == target){
			result.push_back(path);

		}
		//�ݹ�ʵ�ֻ���
		backtracking(result, path, root->left, target, sum);
		backtracking(result, path, root->right, target, sum);
		//�ų�
		sum -= path[path.size() - 1];
		path.pop_back();


	}


	vector<vector<int>> pathSum(TreeNode* root, int target) {

		vector<vector<int>> result;
		if (root == nullptr){
			return result;
		}
		vector<int> path;

		backtracking(result, path, root, target, 0);
		return result;
	}
};

int main(){
	return 0;
}