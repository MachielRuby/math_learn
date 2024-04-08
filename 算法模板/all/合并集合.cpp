//合并集合
#include <iostream>
using namespace std;

const int N = 100010;  // 定义数组大小上限
int n, m;  // 节点数量和操作数量
int p[N], nums[N];  // 并查集数组和集合大小数组

// 实现路径压缩的查找操作，返回节点 x 所属集合的代表节点
int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);  // 如果 x 不是根节点，则将其父节点设为根节点
	return p[x];  // 返回节点 x 所属集合的代表节点
}

int main() {
	cin >> n >> m;  // 输入节点数量和操作数量
	for (int i = 1; i <= n; i++) {
		p[i] = i;  // 初始化每个节点的父节点为自己
		nums[i] = 1;  // 初始化每个节点的集合大小为 1
	}

	while (m--) {
		string op;
		int a, b;
		cin >> op;  // 输入操作类型
		if (op == "C") {  // 如果操作是合并集合
			cin >> a >> b;  // 输入待合并的节点 a 和 b
			if (find(a) != find(b)) {  // 如果 a 和 b 不属于同一个集合
				nums[find(b)] += nums[find(a)];  // 将节点 a 所在集合的大小加到节点 b 所在集合的大小上
				p[find(a)] = find(b);  // 将节点 a 所在集合的代表节点的父节点设为节点 b 所在集合的代表节点，实现合并操作
			}
		}
		else if (op == "Q1") {  // 如果操作是查询是否属于同一集合
			cin >> a >> b;  // 输入待查询的节点 a 和 b
			if (find(a) == find(b)) cout << "Yes" << endl;  // 如果 a 和 b 属于同一个集合，输出 "Yes"
			else cout << "No" << endl;  // 否则输出 "No"
		}
		else {  // 其他操作类型
			cin >> a;  // 输入待查询的节点 a
			cout << nums[find(a)] << endl;  // 输出节点 a 所在集合的大小
		}
	}

	return 0;  // 返回执行成功的状态
}
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
Q2查询多少数量
Q1 查询是否在一块
C 1 2合并集合
