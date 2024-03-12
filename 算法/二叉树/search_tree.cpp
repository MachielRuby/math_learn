#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入新值到二叉搜索树中
TreeNode* insert(TreeNode* node, int val) {
	// 如果当前节点为空，创建一个新节点并返回
	if (node == nullptr) {
		return new TreeNode(val);
	}

	// 否则，递归地插入到左子树或右子树
	if (val < node->val) {
		node->left = insert(node->left, val);
	}
	else if (val > node->val) {
		node->right = insert(node->right, val);
	}

	// 返回未修改的节点指针
	return node;
}

// 用于打印树的辅助函数，这里使用中序遍历
void inOrder(TreeNode* node) {
	if (node == nullptr) return;
	inOrder(node->left);
	cout << node->val << " ";
	inOrder(node->right);
}

int main() {
	TreeNode* root = nullptr;

	// 插入节点
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// 打印中序遍历的结果，可以看到一个有序序列
	cout << "Inorder traversal of the BST: ";
	inOrder(root);
	cout << endl;

	return 0;
}
