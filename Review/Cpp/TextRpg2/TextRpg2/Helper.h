#pragma once

enum MoveDir
{
	MD_NONE,
	MD_LEFT,
	MD_RIGHT,
	MD_UP,
	MD_DOWN,
};

extern MoveDir GMoveDir;

void HandleKeyInput();
void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);