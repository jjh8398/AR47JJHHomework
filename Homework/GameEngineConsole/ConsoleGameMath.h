#pragma once

// ������� �� �����.
class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	inline int2 Half()
	{
		return { X / 2, Y / 2 };
	}

	bool Check(const int2& _Other)
	{
		return X == _Other.X && Y == _Other.Y;
	}

	bool operator==(const int2& _Other) 
	{
		return X == _Other.X && Y == _Other.Y;
	}

	int2 operator+(const int2& _Other) const
	{
		int2 ReturnValue = *this;
		ReturnValue.X += _Other.X;
		ReturnValue.Y += _Other.Y;
		return ReturnValue;
	}

	int2 operator*(const int _Value) const
	{
		int2 ReturnValue = *this;
		ReturnValue.X *= _Value;
		ReturnValue.Y *= _Value;
		return ReturnValue;
	}


public:
	inline int2()
	{

	}

	// �����ڿ� 
	inline int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};