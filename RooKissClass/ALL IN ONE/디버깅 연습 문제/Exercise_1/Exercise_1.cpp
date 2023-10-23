#include <iostream>
using namespace std;
#include "Knight.h"


// [사양서]
// 기사는 생명력(hp), 공격력(attack)을 갖고 있으며
// 기본값은 Hp = 100, Attack = 10입니다.
// 원활한 게임 진행을 위해 기사를 2개 생성하고,
// 1번 기사는 기본값으로,
// 2번 기사는 Hp를 200으로 올려서 설정합니다.

// [Bug Report #1]
// 2번 기사의 정보가 사양서와 일치하지 않습니다.
// 2번 기사의 공격력이 엉뚱한 값(음수)로 되어 있습니다.
// - 공격력이 음수로 설정된 원인을 찾아주세요
// - 2번 기사의 공격력이 기본값(10)으로 설정되길 희망합니다.

// 2번 기사를 생성할 때 다른 생성자에 들어갔는데 초기화 구문이 들어가있지 않습니다
// 해결 방안으로 다른 생성자에 초기화 구문을 넣어주거나 기본 생성자에 진입할 수 있도록 매개변수를 적어주지 않으면 됩니다.
int main()
{
	Knight* k1 = new Knight();
	k1->PrintInfo();
	
	/*Knight* k2 = new Knight(200);*/
	Knight* k2 = new Knight();
	k2->PrintInfo();

	delete k1;
	delete k2;
}
