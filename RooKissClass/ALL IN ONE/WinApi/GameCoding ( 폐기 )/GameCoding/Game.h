#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd); // 초기화
	void Update(); // 매 프레임마다 업데이트
	void Render(); // 그려주는 함수

private:
	HWND _hwnd = {}; // 윈도우 번호
	HDC _hdc = {}; // 도화지 번호
};

