#include "Bullet.h"
#include "Player.h"

Bullet::Bullet()
{
}

void Bullet::MovePos()
{
	Pos = int2{ Pos.X, Pos.Y - 1 };
}

void Bullet::SetPos(int2 _pos)
{
	Pos = _pos;
}

//void Bullet::Fire()
//{
//	if (true == NewPlayer.IsFire())
//	{
//		int2 BulletPos = NewPlayer.GetPos();
//		Bullet::GetABullet().SetPos(int2(NewPlayer.GetPos().X, NewPlayer.GetPos().Y - 1));
//	}


	//ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '^');
//}
