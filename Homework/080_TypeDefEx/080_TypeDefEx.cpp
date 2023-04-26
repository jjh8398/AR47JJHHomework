// 080_TypeDefEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

typedef int MYINT, *MYTEST;

// c의 문법을 거의다 그대로 c++에서 사용할수 있다.
// C++은 C를 포함한다. <= 완 전 개소리

// 문법적으로는 c의 스타일을 거의 다 사용할수 있다.
// 99c를 거의다 사용할수 있다.

// c와 c++의 구조체의 차이는
// c는 맴버함수를 넣을수가 없다.
//struct __tagPlayer
//{
//    int HP;
//    int ATT;
//};
//
//typedef struct __tagPlayer Player;

// 선언과 동시에 typedef를 할수가 있다.
typedef struct __tagPlayer
{
    int HP;
    int ATT;
} Player, Test, *PPlayer;

int main()
{
    int Test;
    int* Ptr0 = nullptr;
    MYTEST Ptr1 = nullptr;

    {
        // 안그러면 컴파일에러나요.
        // struct Player NewPlayer;
        Player NewPlayer;


    }

    // wchar_t* LPWSTR;

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
