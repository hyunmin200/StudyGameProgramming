#include "pch.h"
#include "inputManager.h"

void inputManager::Init(HWND hwnd)
{
}

void inputManager::Update()
{
	BYTE ascilKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(ascilKeys) == false)
		return;

	for(uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		
	}
}
