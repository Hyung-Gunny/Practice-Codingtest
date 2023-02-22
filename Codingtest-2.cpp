#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int denum1, int num1, int denum2, int num2)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);//동적할당을 시켜준다.(배열을 생성해야하기 때문이다.)
    int num3 = 1;//변수 생성

    for (int i = 1; i <= (denum1 * num2 + denum2 * num1); i++)//반복문을 사용하여 분모의 최대공약수를 구해준다
    {
        if ((denum1 * num2 + denum2 * num1) % i == 0 && (num1 * num2) % i == 0)//최대공약수를 구한 후
        {
            num3 = i;//변수에다가 최대공약수를 넣어준다
        }
    }

    answer[0] = (denum1 * num2 + denum2 * num1) / num3;//배열의 분자 값을 넣는다
    answer[1] = (num1 * num2) / num3;//배열의 분모 값을 넣는다.

    return answer;
}