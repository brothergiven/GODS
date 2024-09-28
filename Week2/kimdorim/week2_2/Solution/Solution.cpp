#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numToStr;

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        numToStr.push_back(to_string(*it));

    sort(numToStr.begin(), numToStr.end(), compare);

    if (numToStr[0] == "0")
        return "0";

    for (auto it = numToStr.begin(); it != numToStr.end(); it++)
        answer += *it;

    return answer;
}