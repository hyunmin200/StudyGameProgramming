#include "pch.h"
#include "Board.h"
#include "Player.h"


Board board;
Player player;

int main()
{
	::srand(static_cast<int32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;
	while (true)
	{
		#pragma region 프레임 관리
			const uint64 currentTick = ::GetTickCount64();
			const uint64 deltaTick = currentTick - lastTick;
			lastTick = currentTick;
			// 입력
		#pragma endregion


		// 로직
		player.Update(deltaTick);

		// 렌더링
		board.Render();

	}
}