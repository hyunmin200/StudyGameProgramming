#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	SpaceBar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,

	End
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),
};

class inputManager
{
	DECLARE_SINGLE(inputManager);

public:
	void Init(HWND hwnd);
	void Update();

	// ������ �� ����
	bool GetButton(KeyType type) {}

	// �� ó�� ������ ��

	// ������ �� ��

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
 };

