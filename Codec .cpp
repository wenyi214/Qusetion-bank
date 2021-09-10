//���ò���������Ѽ��ַ����ַ�'a'������ս�㣬�������ֺ����һ��','�������������֣�Ϊ������׼����
//���򻯣�������','�����ַ����浽һstring�����У�ת�������֡����ɽ�㡣
//ת�������֣��õ�stoi��ֻ��ת����10���ƣ��������������ַ������ַ�����ֹͣ������������Χ������
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
	//�ö��в������
	string serialize(TreeNode* root) {
		string s;
		if (root == nullptr){
			return s;
		}
		TreeNode *cur = root;

		queue<TreeNode*> q;
		//����ͷ�ڵ�
		q.push(cur);
		while (!q.empty()){
			cur = q.front();
			q.pop();
			//�ַ�Ϊa�������
			if (cur->val == 1001){
				s += "a";

				delete cur;
				continue;
			}
			else{

				//����תΪ�ַ����������һ��','������ǰ���ַ���
				s += (to_string(cur->val) + ',');
			}
			//��Ϊ�գ���������
			if (cur->left){
				q.push(cur->left);
			}
			//Ϊ�գ�pushһ��1001�Ľ�㣬Ϊ��ʶ����汣���ַ�'a'
			else if (cur->val != 1001 && cur->left == nullptr){

				TreeNode *tmp = new TreeNode(1001);//����ù��캯��
				q.push(tmp);
			}
			//�Ҳ�Ϊ�գ������ҽ��
			if (cur->right){
				q.push(cur->right);
			}
			//Ϊ�գ�pushһ��1001�Ľ�㣬Ϊ��ʶ����汣���ַ�'a'
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
		//������������
		string tmp;
		while (data[j] != ','){
			tmp += data[j];
			j++;

		}
		//���ɽ��
		TreeNode *root = new TreeNode(stoi(tmp));
		q.push(root);
		//ȥ��','
		j++;
		int len = data.size();
		while (!q.empty()){
			TreeNode *cur = q.front();
			q.pop();

			if (data[j] != 'a'){
				//������������
				string t;
				while (j<len&&data[j] != ','){
					t += data[j];
					j++;
				}
				//stoi���ַ���ת��Ϊ10��������
				TreeNode *tmp = new TreeNode(stoi(t));
				cur->left = tmp;
				q.push(cur->left);
			}
			//Ϊa�����ӿ�
			else{
				cur->right = nullptr;

			}
			//ȥ��','����'a'
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
			//Ϊa�����ӿ�
			else{
				cur->right = nullptr;
			}
			//ȥ��','����'a'
			j++;

		}
		return root;
	}
};