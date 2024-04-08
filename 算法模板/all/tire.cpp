
#include<iostream>
using namespace std;
const int N = 1e5 + 10;  // 定义 Trie 的大小常量

// 定义数组存储 Trie 节点和计数器
int q[N][26]; // Trie 节点数组，每个节点最多有 26 个可能的子节点（a-z）
int ctn[N];   // 每个节点的计数器
int idx;      // 跟踪 Trie 中节点的数量

// 向 Trie 中插入字符串的函数
void insert(string s)
{
	int p = 0;  // 从 Trie 的根节点开始
	for (int i = 0; i < s.size(); i++)
	{
		int u = s[i] - 'a'; // 根据 'a' 将字符转换为索引（0-25）
		if (q[p][u] == 0) q[p][u] = ++idx; // 如果节点不存在，则创建新节点
		p = q[p][u]; // 移动到下一个节点
	}
	ctn[p]++; // 增加插入字符串的最后一个节点的计数器
}

// 查询 Trie 中字符串出现次数的函数
int query(string s)
{
	int p = 0;  // 从 Trie 的根节点开始
	for (int i = 0; i < s.size(); i++) {
		int u = s[i] - 'a'; // 根据 'a' 将字符转换为索引（0-25）
		if (q[p][u] == 0) return 0; // 如果字符串不在 Trie 中，则返回 0
		p = q[p][u]; // 移动到下一个节点
	}
	return ctn[p]; // 返回查询字符串的最后一个节点的计数器
}

// 主函数处理输入并执行 Trie 操作
int main()
{
	int n; // 操作数量
	char op; // 操作类型（'I' 表示插入，'Q' 表示查询）
	string s; // 待插入或查询的字符串

	cin >> n; // 输入操作数量
	while (n--) {
		cin >> op >> s; // 输入操作类型和字符串
		if (op == 'I') {
			insert(s); // 如果操作是 'I'，则调用插入函数
		}
		else if (op == 'Q') {
			int c = query(s); // 如果操作是 'Q'，则调用查询函数
			printf("%d\n", c); // 打印查询结果
		}
	}
	return 0;
}
