#include <string>
#include <vector>

using namespace std;

// [1차] 비밀지도 

// 10진수 -> 2진수 (문자열)
string toBinary(int n) {
    string binary = "";
    if (n == 0) {
        return "0";
    } while (n > 0) {
        binary = to_string(n % 2) + binary; // 나머지를 앞에 붙이기
        n = n / 2;
    }
    return binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    // arr1과 arr2의 이진수를 저장할 배열 A, B
    vector<string> A(n);
    vector<string> B(n);
    vector<string> answer(n);

    // 이진수로 변환
    for (int i = 0; i < n; i++) {
        A[i] = toBinary(arr1[i]);
        B[i] = toBinary(arr2[i]);

        // 문자열 길이 n으로 맞춰주기
        while (A[i].size() < n) {
            A[i] = '0' + A[i];
        }
        while (B[i].size() < n) {
            B[i] = '0' + B[i];
        }
    }

    for (int i = 0; i < n; i++) {
        string line = ""; // 한줄씩
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '1' || B[i][j] == '1') { // 둘 중 하나라도 '1'이면 "#"
                line += '#';
            }
            else if (A[i][j] == '0' && B[i][j] == '0') { // 둘 다 '0'이면 " "
                line += " ";
            }
        }
        answer[i] = line;
    }


    return answer;
}