#pragma once

typedef int DataType;

// ���� :
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
		if (this == &_Other) // �ڱ� �ڽŰ��� ���� üũ
			return *this;

		// ���ο� �迭 �Ҵ� �� ����
		DataType* ArrPtr2 = new DataType[_Other.ArrCount];
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr2[i] = _Other.ArrPtr[i];
		}

		// ���� �迭 ����
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		// ���ο� �迭 ����
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
		// 20�� ����.
		// ���� ������ �Ẹ�ø� �����̴ϴ�.

		// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
		// ���Ҹ� ����� �ȵȴ�.

		// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.
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

