#include "Framework.h"

Keyboard::Keyboard()
	: curState{}, oldState{}, mapState{}
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	memcpy(oldState, curState, sizeof(oldState)); //curState가 가리키는 곳부터 oldState의 사이즈만큼 oldState가 가리키는 곳에 복사한다.

	// 0, 1, 128, 129의 값이 나옴
	GetKeyboardState(curState);  // 1 : 키 한번 눌러진 상태 0 : 그 키를 다시 누른상태 (Toggle) 128 : 0상태일때 계속 누르고 있을때 129 : 1상태일때 계속 누르고 있을때
	
	for (int i = 0; i < KEYMAX; i++)
	{
		byte key = curState[i] & 0x80;
		curState[i] = key ? 1 : 0;

		int old = oldState[i];
		int cur = curState[i];

		if (old == 0 && cur == 1)
			mapState[i] = DOWN;
		else if (old == 1 && cur == 0)
			mapState[i] = UP;
		else if (old == 1 && cur == 1)
			mapState[i] = PRESS;
		else
			mapState[i] = NONE;
	}
}
