#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"

#include <windows.h>


int main()
{
	SetCursorOnOff(false);

	//MovePlayer(3, 2);

	while (1)
	{
		// 입력
		HandleKeyInput();

		// 로직
		HandleMove();

		// 출력
		PrintMap2D();
	}
}