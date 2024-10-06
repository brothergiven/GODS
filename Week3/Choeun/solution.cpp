#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        int sum = arr1[i] | arr2[i];

        string line = bitset<16>(sum).to_string();
        line = line.substr(16 - n);

        for (int j = 0; j < n; ++j) {
            if (line[j] == '1') line[j] = '#';
            else line[j] = ' ';
        }
        answer.push_back(line);
    }

    return answer;
}