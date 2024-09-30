#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string& x, const string& y) {
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    vector<string> numbers_str;


    for (int num : numbers) {
        numbers_str.push_back(to_string(num));
    }

    sort(numbers_str.begin(), numbers_str.end(), compare);


    string result;
    for (const string& num : numbers_str) {
        result += num;
    }

    if (result.size()>0 && result[0]=='0') {
        return "0";
    }

    return result;
}

