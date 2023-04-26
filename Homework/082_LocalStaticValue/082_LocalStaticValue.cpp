// 082_LocalStaticValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


static int Value = 0;

void TestFunction() 
{
	std::cout << Value << std::endl;
	++Value;
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		TestFunction();
	}

    std::cout << "Hello World!\n";
}
