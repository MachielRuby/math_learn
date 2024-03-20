#pragma once
#include <iostream>
#include <cassert>
#include <initializer_list> // 必须包含这个头文件
using namespace std;

namespace Gan_list {
	template<class T>
	struct ListNode {
		T _val;
		ListNode* _pPre;
		ListNode* _pNext;

		ListNode(const T& val = T()) : _val(val), _pPre(nullptr), _pNext(nullptr) {}
	};

	template<class T, class Ref, class Ptr>
	class ListIterator {
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;

		ListIterator(PNode pNode = nullptr) : _pNode(pNode) {}
		ListIterator(const Self& l) : _pNode(l._pNode) {}

		Ref operator*() const { return _pNode->_val; }
		Ptr operator->() const { return &(_pNode->_val); }

		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int) {
			Self temp = *this;
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--() {
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self operator--(int) {
			Self temp = *this;
			_pNode = _pNode->_pPre;
			return temp;
		}

		bool operator!=(const Self& l) const { return _pNode != l._pNode; }
		bool operator==(const Self& l) const { return _pNode == l._pNode; }

		PNode _pNode;
	};

	template<class T>
	class list {
	public:
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		list() {
			CreateHead();
		}

		list(std::initializer_list<T> ilist) {
			CreateHead();
			for (const T& value : ilist) {
				push_back(value);
			}
		}

		list(int n, const T& value = T()) {
			CreateHead();
			for (int i = 0; i < n; ++i) {
				push_back(value);
			}
		}

		list(const list<T>& l) {
			CreateHead();
			for (const_iterator it = l.begin(); it != l.end(); ++it) {
				push_back(*it);
			}
		}

		list<T>& operator=(list<T> l) {
			swap(l);
			return *this;
		}

		~list() {
			clear();
			delete _pHead;
		}

		iterator begin() { return iterator(_pHead->_pNext); }
		const_iterator begin() const { return const_iterator(_pHead->_pNext); }
		iterator end() { return iterator(_pHead); }
		const_iterator end() const { return const_iterator(_pHead); }

		size_t size() const {
			size_t count = 0;
			for (const_iterator it = begin(); it != end(); ++it) {
				++count;
			}
			return count;
		}

		bool empty() const {
			return _pHead->_pNext == _pHead;
		}

		T& front() {
			assert(!empty());
			return *begin();
		}

		const T& front() const {
			assert(!empty());
			return *begin();
		}

		T& back() {
			assert(!empty());
			return *(--end());
		}

		const T& back() const {
			assert(!empty());
			return *(--end());
		}

		void push_back(const T& val) {
			insert(end(), val);
		}

		void push_front(const T& val) {
			insert(begin(), val);
		}

		void pop_back() {
			assert(!empty());
			erase(--end());
		}

		void pop_front() {
			assert(!empty());
			erase(begin());
		}

		iterator insert(iterator pos, const T& val) {
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre = pCur->_pPre;
			pCur->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}

		iterator erase(iterator pos) {
			assert(pos._pNode != _pHead); // Can't erase head (sentinel node)
			PNode pDel = pos._pNode;
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			iterator ret(pDel->_pNext);
			delete pDel;
			return ret;
		}

		void clear() {
			while (!empty()) {
				pop_front();
			}
		}

		void swap(list& l) {
			std::swap(_pHead, l._pHead);
		}

	private:
		void CreateHead() {
			_pHead = new Node();
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}

		PNode _pHead;
	};

	void test()
	{

		// 创建一个空链表
		list<int> myList;

		// 测试 push_back 和 push_front
		myList.push_back(10);
		myList.push_back(20);
		myList.push_front(5);
		cout << "After push_back and push_front: ";
		for (auto it = myList.begin(); it != myList.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		// 测试 size 和 empty
		cout << "Size of myList: " << myList.size() << endl;
		cout << "Is myList empty? " << (myList.empty() ? "Yes" : "No") << endl;

		// 测试 front 和 back
		cout << "Front element: " << myList.front() << endl;
		cout << "Back element: " << myList.back() << endl;

		// 测试 pop_back 和 pop_front
		myList.pop_back();
		myList.pop_front();
		cout << "After pop_back and pop_front: ";
		for (auto it = myList.begin(); it != myList.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		// 测试 insert
		auto it = myList.begin();
		++it; // 移动到链表中间的位置
		myList.insert(it, 15);
		cout << "After insert 15 in the middle: ";
		for (auto it = myList.begin(); it != myList.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		// 测试 erase
		it = myList.begin();
		myList.erase(it);
		cout << "After erase the first element: ";
		for (auto it = myList.begin(); it != myList.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		// 测试 clear
		myList.clear();
		cout << "After clear, size of myList: " << myList.size() << endl;

		// 测试拷贝构造函数
		list<int> anotherList = { 1, 2, 3, 4, 5 }; // 假设支持初始化列表
		cout << "Testing copy constructor, anotherList: ";
		for (auto it = anotherList.begin(); it != anotherList.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;



	}
}
