#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> ingredient = { 2,1,1,2,3,1,2,3,1 };
    int answer = 0;
    vector<int> v = {NULL};
    for (auto it = ingredient.begin(); it != ingredient.end(); it++) {
        if (v.back() == 1 && *it == 2) v.back() = 12;
        else if (v.back() == 12 && *it == 3) v.back() = 123;
        else if (v.back() == 123 && *it == 1) answer++, v.pop_back();
        else v.push_back(*it);
    }

    cout <<"number of hamburger is "<< answer;
    return 0;
}
