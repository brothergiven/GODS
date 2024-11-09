#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 붕대감기
// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int success = 0; // 연속 붕대 성공 횟수
    int currentHealth = health; // 현재 채력
    int time = 0; // 현재 시간

    for (int i = 0; i < attacks_rows; i++) {

        while (time < attacks[i][0]) {

            currentHealth += bandage[1]; // 초당 체력 회복
            success++;

            // 최대 체력 넘지 않도록
            if (currentHealth > health) {
                currentHealth = health;
            }
            // 연속 성공시 추가 체력 회복
            if (success == bandage[0]) {
                currentHealth += bandage[2];
                if (currentHealth > health) {
                    currentHealth = health;
                }
                success = 0; // 추가 회복 후 초기화
            }
            time++; // 1초 경과
        }

        currentHealth -= attacks[i][1];
        success = 0; // 공격 당하면 연속 붕대 횟수 초기화

        // 체력이 0이하가 될 경우
        if (currentHealth <= 0) {
            return -1;
        }
        time++;
    }

    return currentHealth;
}