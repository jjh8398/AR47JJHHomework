#pragma once
#include "ConsoleGameMath.h"

class Player;

class Bullet
{
public:

	static Bullet& GetABullet()
	{
		static Bullet ABullet;
		return ABullet;
	}

	void MovePos();

	void SetPos(int2 _pos);

	inline int2 GetPos() const
	{
		return Pos;
	}


private:
	Bullet();

	int2 Pos = int2(0, 0);


};

