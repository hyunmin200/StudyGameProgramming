#include "BinarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

// 지정하고 싶은 위치에 출력하기 위함
void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	// 예외 처리 null이면 return
	if (node == nullptr)
		return;

	// 커서 조정
	SetCursorPosition(x, y);

	cout << node->key;

	// 뒤에 공식은 예쁘게 출력하기 위함임
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	// 못찾으면 nullptr 리턴, 찾으면 찾은 node 리턴
	if (node == nullptr || key == node->key)
		return node;

	// key가 node의 key보다 작으면 왼쪽으로
	if (key < node->key)
		return Search(node->left, key);
	// 아니면 오른쪽으로!
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	// node가 없으면 return
	if (node == nullptr)
		return nullptr;
	// node의 left가 있을 때동안 왼쪽 끝까지 이동
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	// node가 없으면 return
	if (node == nullptr)
		return nullptr;
	// node의 right가 있을 때동안 오른쪽 끝까지 이동
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	// node의 오른쪽이 있다면 오른쪽으로 갔다가 왼쪽으로 쭉가기
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	// parent의 왼쪽이 있다면 탈출
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Insert(int key)
{
	// 새로운 노드 생성
	Node* newNode = new Node();
	// key값 넣어주기
	newNode->key = key;

	// root가 없으면
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	// 추가할 위치를 찾기
	// 위치 추적을 위한 node
	Node* node = _root;
	// 부모님이 누군지
	Node* parent = nullptr;

	// null을 만날 때 까지
	while (node)
	{
		parent = node;
		// left
		if (key < node->key)
			node = node->left;
		// right
		else
			node = node->right;
	}

	newNode->parent = parent;

	// 어디서 추가가 되었는가?
	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	// nullptr 체크
	if (node == nullptr)
		return;

	// 자식 여부에 따라 처리
	
	// 왼쪽 자식이 없을 때
	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	// 오른쪽 자식이 없을 때
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	// 양쪽에 자식이 다 있을 때
	else
	{
		// root 다음으로 큰 수 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	// u가 root라는 뜻
	if (u->parent == nullptr)
		_root = v;
	// u가 부모의 왼쪽 노드일 때
	else if (u == u->parent->left)
		u->parent->left = v;
	// u가 부모의 오른쪽 노드일 때
	else
		u->parent->right = v;

	// 경우따라 nullptr로 넣을 수 있기에 예외처리
	if (v)
		v->parent = u->parent;

	delete u;
}
