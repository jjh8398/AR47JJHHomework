#include "Player.h"
#include "BaseHeader.h"

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Damage(int _Damage) 
{
	if (0 == _Damage)
	{
		// MessageBoxA(nullptr, "�������� 0�Դϴ�", "Error", MB_OK); assert(false);
		MsgBoxAssert("�������� 0�Դϴ�");
	}
}