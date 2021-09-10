//利用层序遍历，搜集字符，字符'a'，代表空结点，正常数字后面加一个','，区分整个数字，为反序化做准备。
//反序化，遍历到','，将字符保存到一string对象中，转化成数字。生成结点。
//转化成数字，用到stoi，只能转化成10进制，遇到不是数字字符或者字符结束停止，超过整数范围，报错。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec {
public:

	// Encodes a tree to a single string.
	//用队列层序遍历
	string serialize(TreeNode* root) {
		string s;
		if (root == nullptr){
			return s;
		}
		TreeNode *cur = root;

		queue<TreeNode*> q;
		//保存头节点
		q.push(cur);
		while (!q.empty()){
			cur = q.front();
			q.pop();
			//字符为a，代表空
			if (cur->val == 1001){
				s += "a";

				delete cur;
				continue;
			}
			else{

				//整数转为字符串，后面加一个','，区分前后字符串
				s += (to_string(cur->val) + ',');
			}
			//左不为空，保存左结点
			if (cur->left){
				q.push(cur->left);
			}
			//为空，push一个1001的结点，为了识别后面保存字符'a'
			else if (cur->val != 1001 && cur->left == nullptr){

				TreeNode *tmp = new TreeNode(1001);//会调用构造函数
				q.push(tmp);
			}
			//右不为空，保存右结点
			if (cur->right){
				q.push(cur->right);
			}
			//为空，push一个1001的结点，为了识别后面保存字符'a'
			else if (cur->val != 1001 && cur->right == nullptr){
				TreeNode *tmp = new TreeNode(1001);
				q.push(tmp);
			}

		}

		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

		if (data.empty()){
			return nullptr;
		}

		queue<TreeNode*> q;
		int j = 0;
		//保存整个数字
		string tmp;
		while (data[j] != ','){
			tmp += data[j];
			j++;

		}
		//生成结点
		TreeNode *root = new TreeNode(stoi(tmp));
		q.push(root);
		//去掉','
		j++;
		int len = data.size();
		while (!q.empty()){
			TreeNode *cur = q.front();
			q.pop();

			if (data[j] != 'a'){
				//保存所有数字
				string t;
				while (j<len&&data[j] != ','){
					t += data[j];
					j++;
				}
				//stoi将字符串转化为10进制整数
				TreeNode *tmp = new TreeNode(stoi(t));
				cur->left = tmp;
				q.push(cur->left);
			}
			//为a，连接空
			else{
				cur->right = nullptr;

			}
			//去掉','或者'a'
			j++;
			if (j<len&&data[j] != 'a'){
				string t;
				while (j<len&&data[j] != ','){
					t += data[j];
					j++;
				}
				TreeNode *tmp = new TreeNode(stoi(t));
				cur->right = tmp;
				q.push(cur->right);
			}
			//为a，连接空
			else{
				cur->right = nullptr;
			}
			//去掉','或者'a'
			j++;

		}
		return root;
	}
};