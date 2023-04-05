#pragma once

typedef int DataType;

// 설명 :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		if (this == &_Other) // 자기 자신과의 대입 체크
			return *this;

		// 새로운 배열 할당 및 복사
		DataType* ArrPtr2 = new DataType[_Other.ArrCount];
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr2[i] = _Other.ArrPtr[i];
		}

		// 기존 배열 삭제
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		// 새로운 배열 대입
		ArrPtr = ArrPtr2;
		ArrCount = _Other.ArrCount;

		return *this;
	}

	size_t Count() 
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value) 
	{
		// 20줄 안팍.
		// 삼항 연산자 써보시면 좋을겁니다.

		// 기존의 할당된 배열을 알고 있는것은 
		// 섣불리 지우면 안된다.

		// 기존의 있던 값에서 현재의 배열이 복사한다음 삭제해야 한다.
		DataType* ArrPtr2 = new DataType[_Value];

		size_t a = _Value < ArrCount ? _Value : ArrCount;

		for (size_t i = 0; i < a; i++)
		{
			ArrPtr2[i] = ArrPtr[i];
		}

		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		ArrPtr = ArrPtr2;
		ArrCount = _Value;
	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};

