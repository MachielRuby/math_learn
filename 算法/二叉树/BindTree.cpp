#include<iostream>
using namespace std;
#include<queue>
#include<vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

//层序遍历
vector<int>leaveOrder(TreeNode* root)
{
	//初始化队列
	queue<TreeNode*> queue;
	queue.push(root);
	//初始化一个列表
	vector<int>vec;
	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();
		vec.push_back(node->val);
		if (node->left != nullptr)
		{
			queue.push(node->left);
		}
		if (node->right != nullptr)
		{
			queue.push(node->right);
		}
	}
	return vec;
}

//前序
//vector<int> preOrder(TreeNode* root)
//{
//	vector<int>s;
//	if (root == nullptr)
//	{
//		return ;
//	}
//	s.push_back(root->val);
//	preOrder(root->left);
//	preOrder(root->right);
//
//}
vector<int> preOrder(TreeNode* root)
{
	vector<int> s;
	if (root == nullptr)
	{
		return s;
	}
	s.push_back(root->val);
	vector<int> left = preOrder(root->left); // 递归调用左子树，并将结果保存在 left 中
	s.insert(s.end(), left.begin(), left.end()); // 将左子树的结果合并到 s 中
	vector<int> right = preOrder(root->right); // 递归调用右子树，并将结果保存在 right 中
	s.insert(s.end(), right.begin(), right.end()); // 将右子树的结果合并到 s 中
	return s; // 返回结果
}


vector<int> inOrder(TreeNode* root)
{
	vector<int>s;
	vector<int>left;
	vector<int>right;
	if (root == nullptr)return s;
	left = inOrder(root->left);
	s.insert(s.end(), left.begin(), left.end());
	s.push_back(root->val);
	right = inOrder(root->right);
	s.insert(s.end(), right.begin(), right.end());
	return s;

}

vector<int> postOrder(TreeNode* root)
{
	vector<int> s;
	if (root == nullptr)
		return s;
	vector<int> left = postOrder(root->left); // 递归调用左子树
	s.insert(s.end(), left.begin(), left.end()); // 将左子树的结果加入 s 中
	vector<int> right = postOrder(root->right); // 递归调用右子树
	s.insert(s.end(), right.begin(), right.end()); // 将右子树的结果加入 s 中
	s.push_back(root->val); // 将当前节点的值加入 s 中
	return s;
}

void print(vector<int>s)
{
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}

TreeNode* search(int num, TreeNode* root)
{
	TreeNode* cur = root;
	while (cur != nullptr)
	{
		if (cur->val < num)
			cur = cur->right;
		else if (cur->val > num)
			cur = cur->left;
		else break;
	}
	return cur;

}
void test01()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	vector<int>s;
	s = leaveOrder(n1);
	print(s);
	s = preOrder(n1);
	print(s);
	s = inOrder(n1);
	print(s);
	s = postOrder(n1);
	print(s);
	TreeNode* num = search(5, n1);
	if (num)cout << num->val;

}
int main()
{
	test01();
	return 0;
}