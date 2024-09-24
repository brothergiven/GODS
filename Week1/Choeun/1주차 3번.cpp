#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        while (arr[i] == arr[i + 1])
            i++;
        answer.push_back(arr[i]);
    }


    return answer;
}