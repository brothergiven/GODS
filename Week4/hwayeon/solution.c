#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �ش밨��
// bandage_len�� �迭 bandage�� �����Դϴ�.
// attacks_rows�� 2���� �迭 attacks�� �� ����, attacks_cols�� 2���� �迭 attacks�� �� �����Դϴ�.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int success = 0; // ���� �ش� ���� Ƚ��
    int currentHealth = health; // ���� ä��
    int time = 0; // ���� �ð�

    for (int i = 0; i < attacks_rows; i++) {

        while (time < attacks[i][0]) {

            currentHealth += bandage[1]; // �ʴ� ü�� ȸ��
            success++;

            // �ִ� ü�� ���� �ʵ���
            if (currentHealth > health) {
                currentHealth = health;
            }
            // ���� ������ �߰� ü�� ȸ��
            if (success == bandage[0]) {
                currentHealth += bandage[2];
                if (currentHealth > health) {
                    currentHealth = health;
                }
                success = 0; // �߰� ȸ�� �� �ʱ�ȭ
            }
            time++; // 1�� ���
        }

        currentHealth -= attacks[i][1];
        success = 0; // ���� ���ϸ� ���� �ش� Ƚ�� �ʱ�ȭ

        // ü���� 0���ϰ� �� ���
        if (currentHealth <= 0) {
            return -1;
        }
        time++;
    }

    return currentHealth;
}