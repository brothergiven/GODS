#include <vector>
#include <iostream>

using namespace std;

// 3 같은 숫자는 싫어
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr[0]);

    for (int i = 1, j = 0; i < arr.size(); i++) {
        if (arr[i] == answer[j]) {
            continue;
        }
        else {
            answer.push_back(arr[i]);
            j++;
        }
    }
    return answer;
}