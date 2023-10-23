#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}

public:
	T		data;
	Node* prev;
	Node* next;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr) {}
	// 노드 지정시 저장
	Iterator(Node<T> node) : _node(node) {}

	// ++it
	Iterator& operator++()
	{
		// 현재 노드에 다음노드 저장
		_node = _node->next;
		return *this;
	}

	// it++
	Iterator operator++(int)
	{
		Iterator temp = *this;
		// 현재 노드에 다음노드 저장
		_node = _node->next;
		return temp;
	}

	T& operator*()
	{
		return _node->data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}
public:
	Node<T> _node;
};



template<typename T>
class List
{
public:
	using iterator = Iterator<T>;

	// dummy 노드 다음 노드가 첫 번쨰 노드
	iterator begin() { return iterator(_head->next); }
	// dummy 노드가 마지막 다음이기에 _tail
	iterator end() { return iterator(_tail); }

	List()
	{
		_head = new Node<T>(0);
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node<T>* node = _head;
		while (node)
		{
			Node<T>* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}

	// [dummy]<->[1]<->[2]<->[3]<->[dummy]
	// [head]						[tail]
	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;
		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node<T>* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	Node<T>* Remove(Node<T>* node)
	{
		Node<T>* prevNode = node->prev;
		Node<T>* nextNode = node->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
};

