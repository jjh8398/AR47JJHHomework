#include "Player.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Bullet.h"

Player::Player()
	: BulletPtr(nullptr)
{

}
// ȭ��ٱ����� �������� �ϼ���. 

// ���� �Ѿ� ��ȣ
int CurBulletCount = 0;

void Player::Input()
{
	if (0 == _kbhit())
	{
		// 0.5�ʰ� �����.
		Sleep(InterFrame);
		// �Ϻη� ���߰� ����̴ϴ�.
		// continue; �ݺ��� ���ο����� ��밡��
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };
	
	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.X -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.X += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.X += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.Y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.Y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.Y += 1;
		}
		break;
	case 'f':
	case 'F':
		//BulletPtr->Shoot();
		if (CurBulletCount < Bullet::ArrBulletCount)
        {
			BulletPtr[CurBulletCount].SetPos(Pos);
			BulletPtr[CurBulletCount].FireOn();
        	++CurBulletCount;
        }
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}


void Player::Render()
{
	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '*');
}