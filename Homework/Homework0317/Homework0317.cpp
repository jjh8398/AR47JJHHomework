// HomeWork0317.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요

// 글자의 개수를 세는 함수 (0을 포함하는 경우)
int StringCount(const char* _String)
{
	// 숫자를 세기 위한 숫자세기 변수를 선언한다.
	// 이 변수는 0부터 시직한다.
	int count = 0;

	// _String의 처음부터 값을 확인한다. 그 값이 0이 아닌 경우에
	while (_String[count])
	{
		// 값 확인
		char Ch = _String[count];

		//숫자를 더한다.
		++count;
	}
	//_String[count]의 값이 0일 경우에는 while문을 나온다.

	// 숫자를 반환한다.
	return count;
}


// 글자의 개수를 세는 함수 (0을 포함하지 않는 경우)
int StringCount2(const char* _String)
{
	// 숫자를 세기 위한 숫자세기 변수를 선언한다.
	// 이 변수는 0부터 시직한다.
	int count = 0;
	// 공백을 제외하고 세기 위한 변수를 하나 더 선언한다.
	int StrCount = 0;

	// _String의 처음부터 값을 확인한다. 그 값이 0이 아닌 경우에
	while (_String[StrCount])
	{
		// 값 확인
		char Ch = _String[StrCount];

		// 그 값이 공백도 아니라면
		if (' ' != _String[StrCount])
		{
			// 숫자를 더한다
			++count;
		}
		//글자를 세는 숫자를 더한다.
		++StrCount;
	}
	//_String[count]의 값이 0일 경우에는 while문을 나온다.

	// 숫자를 반환한다.
	return count;
}


// 글자의 공백을 지우는 함수
int TrimDelete(char* _String)
{
	char* String = _String;
	int i = 0;
	int j = 0;

	// String[i]의 값이 존재하면 (null문자가 아닌 동안에)
	while (String[i])
	{
		// String[i]값 확인
		char Ch = String[i];

		// String[i]가 공백이 아니라면
		if (' ' != String[i])
		{
			// String[i]의 값을 String[j]에 넣음
			String[j] = String[i];
			// j를 1개 더함
			j++;
		}
		// String[i]의 공백 여부와 상관없이 i를 더함
		i++;
	}

	// String[i]의 값이 더 이상 존재하지 않으면 String[j]에 공백 문자를 적음.
	String[j] = '\0';

	return 0;
}

// 문자에 있는 숫자를 정수형으로 바꾸는 함수
int StringToInt(const char* _String)
{
	int i = 0;
	int value = 0;

	while (0 != _String[i])
	{
		value *= 10;
		int j = _String[i] - 48;
		value += j;
		++i;
	}

	return value;
}

int main()
{
	int Return0 = StringCount("aaaa");
	int Return1 = StringCount("aaaa ggg sss");

	char Arr0[1024] = "a b c d e";
	char Arr1[1024] = "a    b c    d    e";
	char Arr2[1024] = "ab    cde    ";

	StringCount(Arr0);
	StringCount(Arr1);
	StringCount(Arr2);
	StringCount2(Arr0);
	StringCount2(Arr1);
	StringCount2(Arr2);

	TrimDelete(Arr0);
	printf_s(Arr0);
	TrimDelete(Arr1);
	printf_s(Arr1);
	TrimDelete(Arr2);
	printf_s(Arr2);

	// 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
	int RValue0 = StringToInt("1111");
	int RValue1 = StringToInt("432");
	int RValue2 = StringToInt("4523312");
	int RValue3 = StringToInt("432231");

	std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
