#include "Monster.h"
#include "ConsoleGameScreen.h"
#include "ShootingGame.h"

Monster::Monster() 
{
	RenderChar = 'M';
}

void Monster::Update() 
{
	if (false == IsUpdate())
	{
		return;
	}
}

int Monster::GetMonsterDir()
{
	return Dir;
}

void Monster::ChangeMonsterDir()
{
	Dir *= -1;
}