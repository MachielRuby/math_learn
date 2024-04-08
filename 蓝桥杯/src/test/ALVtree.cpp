#include<iostream>
using namespace std;

template<class K, class V>
struct ALVTreeNode
{
	ALVTreeNode<K, V>* _left; //左子树
	ALVTreeNode<K, V>* _right; //右子树
	ALVTreeNode<K, V>* _parent; //节点双亲

	int _bf;//平衡因子
	pair<K, V> _kv;
};


template<class K, class V>
class ALVTree
{
	typedef ALVTreeNode<K, B>Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				//parent所在子树的高度不变更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//说明高度变了继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent子树出现问题需要旋转处理
			}
		}
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		//原来parent是根现在subR是根
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if ()
		}
	}

	void RotateR(Node* parent)
	{
		Node* child = parent->_left;
		parent->_left = child->_right;
		child->_right = parent;
	}
private:
	Node* _root = nullptr;
};
int main()
{

	return 0;
}