#include <stdio.h>
#include <stdlib.h>

int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int t = bandage[0]; // 시전 시간 t
    int x = bandage[1]; // 초당 회복량 x
    int y = bandage[2]; // 추가 회복량 y
    int success = 0; // 연속 성공 시간
    int time = 0; // 현재 시간
    int answer = health; // 현재 체력 = 최대체력
    int n = 0; // attack의 행

    while (time <= attacks[attacks_rows - 1][0]) { // 공격 배열 끝까지
        if (time == attacks[n][0]) { //공격 받음
            answer -= attacks[n][1];  // 현재 체력 - 피해량
            success = 0;  // 연속 성공 시간 초기화
            if (answer <= 0) {  // 체력이 0 이하 죽음
                return -1;
            }
            n++;  // 공격 배열 인덱스 증가
        }
        else { //공격 안받음
            if (answer < health) { // 현재 체력 < 최대 체력
                if (success < t) {  // 연속 성공 시간 불만족
                    answer += x;  // 현재 체력 + 초당 회복량
                    if (answer > health) {  // 최대 체력 초과
                        answer = health; // 최대 체력으로 초기화
                    }
                    success++;  // 연속 성공 시간 증가
                }

                if (success == t) { // 연속 성공 시간 만족
                    answer += y;  // 현재 체력 + 추가 회복량 
                    if (answer > health) {  // 최대 체력 초과
                        answer = health; // 최대 체력으로 초기화
                    }
                    success = 0;  // 연속 성공 초기화
                }
            }
        }
        time++;  // 시간 1초 증가
    }
    return answer;  // 최종 체력 반환
}