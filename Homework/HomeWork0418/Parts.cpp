#include "Parts.h"

Parts::Parts() 
{
}

Parts::~Parts() 
{
}

void Parts::Update() 
{
	PartDirection();
	ConsoleGameObject::Update();
}

void Parts::NextMove()
{
	Parts* Next = GetNext();
	
	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());
	return Next->NextMove();
}

void Parts::Direction()
{
	// int2 Dir = Next - Prev;
}

void Parts::PartDirection()
{
	if (Dir == int2::Left)
		RenderChar = L'��';
	if (Dir == int2::Right)
		RenderChar = L'��';
	if (Dir == int2::Up)
		RenderChar = L'��';
	if (Dir == int2::Down)
		RenderChar = L'��';
}
