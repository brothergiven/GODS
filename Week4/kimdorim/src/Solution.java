public class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int playerHealth = health;
        int time = 0;
        int lastAttackTime = attacks[attacks.length - 1][0];

        for (int i = 0; i <= lastAttackTime; i++) {
            boolean attacked = false; // flag

            for (int[] attack : attacks) {
                if (attack[0] == i) { // 현재 시간이 공격 시간과 일치할 때
                    playerHealth -= attack[1];
                    attacked = true;
                    time = 0;
                    break;
                }
            }

            if (!attacked) { // 공격이 없을 때만 회복 로직 실행
                playerHealth += bandage[1];
                time += 1;

                if (time == bandage[0]) {
                    playerHealth += bandage[2];
                    time = 0;
                }

                if (playerHealth >= health) {
                    playerHealth = health;
                }
            }

            if (playerHealth <= 0) {
                return -1;
            }
        }

        return playerHealth;
    }
}
