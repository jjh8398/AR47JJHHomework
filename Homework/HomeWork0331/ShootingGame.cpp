#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알과
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	// 1. 움직이게 한다.
		
	// 2. 끝에 어떠한 몬스터중 단 1개라도 닿았는지 확인한다.
	//    2-1. 왼쪽 끝을체크한다.
	//    2-2. 오른쪽 끝에 닿은걸 체크한다.
	//if (몬스터가 왼쪽 끝에 닿았다)
	//{
	//	int a = 0;
	//}

	// 3. 방향을 바꾼다.

	// 4. 내려도 본다.

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		int NewX = ArrMonster[i].GetPos().X - ArrMonster->GetMonsterDir();
		int NewY = ArrMonster[i].GetPos().Y;
		int2 NewPos = int2(NewX, NewY);

		ArrMonster[i].SetPos(NewPos);
	}

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		if (-1 == ArrMonster[i].GetPos().X || ConsoleGameScreen::ScreenXSize == ArrMonster[i].GetPos().X)
		{
			ArrMonster->ChangeMonsterDir();
			for (int j = 0; j < ArrMonsterCount; j++)
			{
				int NewX = ArrMonster[j].GetPos().X - ArrMonster->GetMonsterDir();
				int NewY = ArrMonster[j].GetPos().Y + 1;
				int2 NewPos = int2(NewX, NewY);

				ArrMonster[j].SetPos(NewPos);
			}
		}
	}
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}