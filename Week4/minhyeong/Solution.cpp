#include <iostream>
#include <vector>
#include <algorithm>  // std::max

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int row = board.size();
    int col = board[0].size();

    vector<vector<int>> sq(row, vector<int>(col, 0));


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 1) {
                if (i == 0 || j == 0) {
                    sq[i][j] = 1;  // 첫 번째 행과 열은 1로 설정  주변 행,열과 비교 불가
                }
                else {
                    // Sp[i][j]는 위, 왼쪽, 대각선 값 중 최소값 + 1 전부 깂이 있다면 1 커짐 
                    sq[i][j] = min({ sq[i - 1][j], sq[i][j - 1], sq[i - 1][j - 1] }) + 1;
                }
                //  가장큰 변 있다면 갱신 
                answer = max(answer, sq[i][j]);
            }
        }
    }

    
    return answer * answer;
}

int main() {
    vector<vector<int>> s = { {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 1},
                              {0, 0, 1, 0} };
    cout << solution(s) << endl;  

    return 0;}