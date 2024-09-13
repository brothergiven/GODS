#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// 2 햄버거 만들기
// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int stack[1000000];
    int answer = 0;
    int top = 0;
    for (int i = 0; i < ingredient_len; i++) {
        stack[top++] = ingredient[i];
        if (top >= 3 && stack[top] == 1) {
            if (stack[top - 1] == 3 && stack[top - 2] == 2 && stack[top - 3] == 1) {
                answer++;
                top = top - 4;
            }
        }
    }

    return answer;
}
