 #include <string>
#include <vector>
#include <iostream> // 디버깅용 추가
    
using namespace std;

int solution(vector<int> ingredient) {
    int count = 0;
    vector<int> v;
    for (int i = 0; i < ingredient.size(); i++) {
        if (ingredient[i] == 2 && !v.empty() && v.back() == 1) {
            v.back() = 12;
        } else if (ingredient[i] == 3 && !v.empty() && v.back() == 12) {
            v.back() = 123;
        } else if (ingredient[i] == 1 && !v.empty() && v.back() == 123) {
            v.back() = 1231;
            v.pop_back();
            count++;
        }
          else
            v.push_back(ingredient[i]);
    }
    return count;
}
