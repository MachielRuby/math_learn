#include<cstdio>
#include<string>
#include<vector>			//每个木块堆的高度不确定，所以用vector来保存更合适 
#include<iostream>
using namespace std;

const int N = 35;
int n;
vector<int> pile[N]; 		//每个pile是一个vector

//找出木块a所在的pile和hight,以引用的形式返回调用者 
void find_block(int a, int& p, int& h) {
	for (p = 0; p < n; p++) {
		for (h = 0; h < pile[p].size(); h++) {
			if (pile[p][h] == a) {
				return;
			}
		}
	}
}

//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p, int h) {
	for (int i = h + 1; i < pile[p].size(); i++) {
		int b = pile[p][i];
		pile[b].push_back(b);//把木块b放回原位 
	}
	pile[p].resize(h + 1);    //pile只保留下标0-h的元素 
}

//把第p堆高度为h及其上方的木块整体移动到p2的顶端
void pile_onto(int p, int h, int p2) {
	for (int i = h; i < pile[p].size(); i++) {
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

void print() {
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		for (int j = 0; j < pile[i].size(); j++) {
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int a, b;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		pile[i].push_back(i);
	}
	while (1) {
		cin >> s1;
		if (s1 == "quit") {
			break;
		}
		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if (pa == pb) {
			continue;
		}						//非法指令 
		if (s2 == "onto") {
			clear_above(pb, hb);
		}
		if (s1 == "move") {
			clear_above(pa, ha);
		}
		pile_onto(pa, ha, pb);
	}
	print();

	return 0;
}