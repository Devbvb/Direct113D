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
	memcpy(oldState, curState, sizeof(oldState)); //curState�� ����Ű�� ������ oldState�� �����ŭ oldState�� ����Ű�� ���� �����Ѵ�.

	// 0, 1, 128, 129�� ���� ����
	GetKeyboardState(curState);  // 1 : Ű �ѹ� ������ ���� 0 : �� Ű�� �ٽ� �������� (Toggle) 128 : 0�����϶� ��� ������ ������ 129 : 1�����϶� ��� ������ ������
	
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
