#include<iostream>
#include<vector>
using namespace std;

class ArrayBinaryTree {
public:
	// 构造方法
	ArrayBinaryTree(vector<int> arr) {
		tree = arr;
	}
	// 列表容量
	int size() {
		return tree.size();
	}
	// 获取索引为 i 的节点的值
	int val(int i) {
		if (i < 0 || i >= size()) {
			return INT_MAX; // 返回一个表示无效值的标记
		}
		return tree[i];
	}

	int left(int i) {
		return 2 * i + 1;
	}

	int right(int i) {
		return 2 * i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	// 层序遍历
	vector<int> leaveOrder() {
		vector<int> res;
		// 遍历数组
		for (int i = 0; i < size(); i++) {
			if (val(i) != INT_MAX) {
				res.push_back(val(i));
			}
		}
		return res;
	}

	// 前序遍历
	vector<int> preOrder() {
		vector<int> res;
		dfs(0, "pre", res);
		return res;
	}

	// 中序遍历
	vector<int> inOrder() {
		vector<int> res;
		dfs(0, "in", res);
		return res;
	}

	// 后序遍历
	vector<int> postOrder() {
		vector<int> res;
		dfs(0, "post", res);
		return res;
	}
private:
	vector<int> tree;

	// 深度优先遍历辅助函数
	void dfs(int i, string order, vector<int>& res) {
		if (val(i) == INT_MAX) {
			return;
		}
		// 前序遍历
		if (order == "pre")
			res.push_back(val(i));
		dfs(left(i), order, res);
		// 中序遍历
		if (order == "in")
			res.push_back(val(i));
		dfs(right(i), order, res);
		// 后序遍历
		if (order == "post") {
			res.push_back(val(i));
		}
	}
};

int main() {
	// 创建一个数组二叉树
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	ArrayBinaryTree tree(arr);

	// 层序遍历
	vector<int> leaveRes = tree.leaveOrder();
	cout << "Level Order Traversal: ";
	for (int val : leaveRes) {
		cout << val << " ";
	}
	cout << endl;

	// 前序遍历
	vector<int> preRes = tree.preOrder();
	cout << "Preorder Traversal: ";
	for (int val : preRes) {
		cout << val << " ";
	}
	cout << endl;

	// 中序遍历
	vector<int> inRes = tree.inOrder();
	cout << "Inorder Traversal: ";
	for (int val : inRes) {
		cout << val << " ";
	}
	cout << endl;

	// 后序遍历
	vector<int> postRes = tree.postOrder();
	cout << "Postorder Traversal: ";
	for (int val : postRes) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
