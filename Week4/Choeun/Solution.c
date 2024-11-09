#include <stdio.h>
#include <stdlib.h>

int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int t = bandage[0]; // ���� �ð� t
    int x = bandage[1]; // �ʴ� ȸ���� x
    int y = bandage[2]; // �߰� ȸ���� y
    int success = 0; // ���� ���� �ð�
    int time = 0; // ���� �ð�
    int answer = health; // ���� ü�� = �ִ�ü��
    int n = 0; // attack�� ��

    while (time <= attacks[attacks_rows - 1][0]) { // ���� �迭 ������
        if (time == attacks[n][0]) { //���� ����
            answer -= attacks[n][1];  // ���� ü�� - ���ط�
            success = 0;  // ���� ���� �ð� �ʱ�ȭ
            if (answer <= 0) {  // ü���� 0 ���� ����
                return -1;
            }
            n++;  // ���� �迭 �ε��� ����
        }
        else { //���� �ȹ���
            if (answer < health) { // ���� ü�� < �ִ� ü��
                if (success < t) {  // ���� ���� �ð� �Ҹ���
                    answer += x;  // ���� ü�� + �ʴ� ȸ����
                    if (answer > health) {  // �ִ� ü�� �ʰ�
                        answer = health; // �ִ� ü������ �ʱ�ȭ
                    }
                    success++;  // ���� ���� �ð� ����
                }

                if (success == t) { // ���� ���� �ð� ����
                    answer += y;  // ���� ü�� + �߰� ȸ���� 
                    if (answer > health) {  // �ִ� ü�� �ʰ�
                        answer = health; // �ִ� ü������ �ʱ�ȭ
                    }
                    success = 0;  // ���� ���� �ʱ�ȭ
                }
            }
        }
        time++;  // �ð� 1�� ����
    }
    return answer;  // ���� ü�� ��ȯ
}