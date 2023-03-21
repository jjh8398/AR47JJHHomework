﻿// 008_Bit.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    // 00000000 00000000 00000000 00000001
    int Value = 1; int Value1 = 1;

    // 00000000 00000000 00000000 00000011
    Value = 2;

    // 2진수 표현하는법
    Value = 0b00000000100000000000000000000011;

    //        8421
    // 자료형은 여러분들이 판단하는게 아니라 컴파일러에게 물어봐야하고
    // 내가 직접 확인해야 하는겁니다.
    Value = 0b1011;

    Value = 0b11111111111111111111111111111111;

    //  + 0
    Value = 0b00000000000000000000000000000000;
    // 2의 보수법이라는 표현을 통해서 이 논리적 허점을 피해가면서도 모든 숫자를 표현하는 방법을
    
    // c++의 정수에 대한 비트 표현방식으로 사용하기로 했다.
    Value = 0b10000000000000000000000000000000;

    // 음수를 표현할때는 역수를 취하기로 했다.
    Value = 0b11111111111111111111111111111110;

    // Value = 0b11111111111111111111111111111011; == -1이라고 본다
    //        ▽ 맨 앞의 32번째 비트를 부호비트라고 선언하기로 했다. 
    //           그리고 나서 그부호비트가 1이면 무조건 음수로 처리하기로 하고
    //            2의 보수법을 기본으로한 오히려 비트가 0이면 더해주는 방식으로 처리하기로 결정했다.
    Value = 0b11111111111111111111111111111011;
    //                                       1
}