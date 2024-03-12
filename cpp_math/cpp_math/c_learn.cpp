#include<iostream>
using namespace std;
#include<stack>
//二叉树节点
struct BinTree
{
	char ch;
	BinTree* lchild;
	BinTree* rchild;
};

//先序
void print(BinTree* A)
{
	if (A == NULL)return;
	cout << A->ch << " ";
	print(A->lchild);
	print(A->rchild);
}
//中序
void printl(BinTree* A)
{
	if (A == NULL)return;
	printl(A->lchild);
	cout << A->ch << " ";
	printl(A->rchild);
}
void calculate(BinTree* A, int& num)
{
	if (A == NULL)return;
	if (A->lchild == NULL && A->rchild == NULL)
	{
		num++;
	}
	calculate(A->lchild, num);
	calculate(A->rchild, num);
}

int getTreeHeight(BinTree* A)
{
	if (A == NULL)
	{
		return 0;
	}
	//获取左边高度
	int lheight = getTreeHeight(A->lchild);
	int rheight = getTreeHeight(A->rchild);
	int height = lheight > rheight ? lheight + 1 : rheight + 1;
	return height;

}

//拷贝二叉树
BinTree* copyTree(BinTree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	//拷贝左子树
	BinTree* lchild = copyTree(root->lchild);
	//拷贝右子树
	BinTree* rchild = copyTree(root->rchild);
	//创建新节点
	BinTree* newNode = new BinTree;
	//拷贝的左右挂到新节点
	newNode->lchild = lchild;
	newNode->rchild = rchild;
	newNode->ch = root->ch;
	//返回结果
	return newNode;
}
//释放
void freeTree(BinTree* root)
{
	if (root == NULL)return;
	//先释放左边
	freeTree(root->lchild);
	freeTree(root->rchild);
	cout << "释放了" << root->ch << " ";
	free(root);
}

void nonRecursion(BinTree* root)
{
	// 初始化栈
	stack<BinTree*> stack;
	stack.push(root);
	// 只要栈中元素>0
	while (!stack.empty())
	{
		// 获取栈顶元素
		BinTree* topNode = stack.top();
		// 出栈
		stack.pop();
		if (topNode)
		{
			cout << topNode->ch << " ";
			// 将右子节点压入栈中
			if (topNode->rchild)
				stack.push(topNode->rchild);
			// 将左子节点压入栈中
			if (topNode->lchild)
				stack.push(topNode->lchild);
		}
	}
}

void test01()
{
	BinTree A = { 'A',NULL,NULL };
	BinTree B = { 'B',NULL,NULL };
	BinTree C = { 'C',NULL,NULL };
	BinTree D = { 'D',NULL,NULL };
	BinTree E = { 'E',NULL,NULL };
	BinTree F = { 'F',NULL,NULL };
	BinTree G = { 'G',NULL,NULL };
	BinTree H = { 'H',NULL,NULL };
	A.lchild = &B;
	A.rchild = &F;
	B.rchild = &C;
	C.lchild = &D;
	C.rchild = &E;
	F.rchild = &G;
	G.lchild = &H;
	printl(&A);

	//统计二叉树叶子的数量	
	int num = 0;
	calculate(&A, num);
	cout << endl << "叶子的数量 = " << num << endl;

	//统计树的高度 
	int height = getTreeHeight(&A);
	cout << "高度为: " << height << endl;
	BinTree* newNode = copyTree(&A);
	print(newNode);
	cout << endl;
	freeTree(newNode);
	cout << endl;
	nonRecursion(&A);
}

int main()
{
	test01();
	return 0;
}