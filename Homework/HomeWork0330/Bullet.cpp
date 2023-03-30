#include "Bullet.h"
#include "ConsoleGameScreen.h"
#include <conio.h>
#include <Windows.h>
#include "Player.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

// 현재 총알 번호
// int CurBulletCount = 0;


void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Render();
	}

}

void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Update();
	}
}

Bullet::Bullet()
{

}

//void Bullet::Shoot()
//  {
//	if (CurBulletCount < Bullet::ArrBulletCount)
//	{
//		ArrBullet[CurBulletCount].SetPos(Pos);
//		ArrBullet[CurBulletCount].FireOn();
//		++CurBulletCount;
//	}
//}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos, '^');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos1, '^');
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(Pos2, '^');
	}
}

void Bullet::Update() 
{
	if (true == Fire)
	{
		--Pos.Y;
		--Pos1.Y;
		--Pos1.X;
		--Pos2.Y;
		++Pos2.X;
	}
}