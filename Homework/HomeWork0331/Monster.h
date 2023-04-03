#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();
	int GetMonsterDir();
	void ChangeMonsterDir();

private:
	int Dir = 1;
};

