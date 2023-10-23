#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
	// 나중에 템플릿으로 바꿈
	//typedef int T; // 옛날 문법(C)
	//using T = int; // 현재 문법
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}

public:
	T		data;
	Node*	next;
	Node*	prev;
};

template<typename T>
class List
{
public:
	List()
	{
		// 더미 노드
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
			// 커서 개념
			node = node->next;
			delete deleteNode;
		}
	}

	//[dummy]<->[1]<->[2]<->[3]<->[dummy]
	//[head]						[tail]
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

	//[dummy]<->[1]<->[2]<->[3]<->[dummy]
	//[head]						[tail]
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

	//      [node]
	//[dummy]<- ->[nextNode]<->[2]<->[3]<->[dummy]
	//[head]								[tail]
	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		node->prev = _head;
		_head->next = node;

		return node;
	}

	//                               [node]
	//[dummy]<->[1]<->[2]<->[prevNode]<- ->[dummy]
	//[head]								[tail]
	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		node->next = _tail;
		node->prev = prevNode;
		_tail->prev = node;
		prevNode->next = node;

		return node;
	}

	//			         [node]
	//[dummy]<->[prevNode]<- ->[posNode]<->[3]<->[dummy]
	//[head]						[tail]
	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		posNode->prev = node;
		node->next = posNode;
	}
	
	//[dummy]<->[prevNode]<->[node]<->[nextNode]<->[dummy]
	//[head]						[tail]
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