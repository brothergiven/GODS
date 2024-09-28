
/*

햄버거 찾기
빵 - 야채 - 고기 - 빵이 햄버거임

배열이 들어왔을 때 빵 - 야채 - 고기 - 빵 순서인 것만 읽어서

배열에서 검사하면서
1 2 3 1 이면 count ++

이게 몇개인지????? 를 카운트



*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len)
{
    int answer = 0;
    int stack[1000000]; // stack의 최대 크기 백만
    int top = 0;

    for (int i = 0; i < ingredient_len; i++)
    {
        stack[top++] = ingredient[i]; // push

        // push 한 다음에
        // 밑에 4개 검사

        if (top >= 4)
        {
            if (stack[top - 1] == 1 &&
                stack[top - 2] == 3 &&
                stack[top - 3] == 2 &&
                stack[top - 4] == 1)
            {
                answer++;
                top -= 4;
            }
        }
    }

    return answer;
}