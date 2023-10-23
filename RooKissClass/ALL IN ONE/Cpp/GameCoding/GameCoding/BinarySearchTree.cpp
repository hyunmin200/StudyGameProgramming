#include "BinarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

// �����ϰ� ���� ��ġ�� ����ϱ� ����
void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	// ���� ó�� null�̸� return
	if (node == nullptr)
		return;

	// Ŀ�� ����
	SetCursorPosition(x, y);

	cout << node->key;

	// �ڿ� ������ ���ڰ� ����ϱ� ������
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	// ��ã���� nullptr ����, ã���� ã�� node ����
	if (node == nullptr || key == node->key)
		return node;

	// key�� node�� key���� ������ ��������
	if (key < node->key)
		return Search(node->left, key);
	// �ƴϸ� ����������!
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	// node�� ������ return
	if (node == nullptr)
		return nullptr;
	// node�� left�� ���� ������ ���� ������ �̵�
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	// node�� ������ return
	if (node == nullptr)
		return nullptr;
	// node�� right�� ���� ������ ������ ������ �̵�
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	// node�� �������� �ִٸ� ���������� ���ٰ� �������� �߰���
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;

	// parent�� ������ �ִٸ� Ż��
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

void BinarySearchTree::Insert(int key)
{
	// ���ο� ��� ����
	Node* newNode = new Node();
	// key�� �־��ֱ�
	newNode->key = key;

	// root�� ������
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	// �߰��� ��ġ�� ã��
	// ��ġ ������ ���� node
	Node* node = _root;
	// �θ���� ������
	Node* parent = nullptr;

	// null�� ���� �� ����
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

	// ��� �߰��� �Ǿ��°�?
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
	// nullptr üũ
	if (node == nullptr)
		return;

	// �ڽ� ���ο� ���� ó��
	
	// ���� �ڽ��� ���� ��
	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	// ������ �ڽ��� ���� ��
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	// ���ʿ� �ڽ��� �� ���� ��
	else
	{
		// root �������� ū �� ã��
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	// u�� root��� ��
	if (u->parent == nullptr)
		_root = v;
	// u�� �θ��� ���� ����� ��
	else if (u == u->parent->left)
		u->parent->left = v;
	// u�� �θ��� ������ ����� ��
	else
		u->parent->right = v;

	// ������ nullptr�� ���� �� �ֱ⿡ ����ó��
	if (v)
		v->parent = u->parent;

	delete u;
}
