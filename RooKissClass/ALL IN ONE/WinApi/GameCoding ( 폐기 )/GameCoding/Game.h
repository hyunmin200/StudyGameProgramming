#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd); // �ʱ�ȭ
	void Update(); // �� �����Ӹ��� ������Ʈ
	void Render(); // �׷��ִ� �Լ�

private:
	HWND _hwnd = {}; // ������ ��ȣ
	HDC _hdc = {}; // ��ȭ�� ��ȣ
};

