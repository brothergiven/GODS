#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &x, string &y){
    return x+y > y+x;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> finalNum;
    
    for(int i = 0; i < numbers.size(); i++){
        finalNum.push_back(to_string(numbers[i]));
    }
    
    sort(finalNum.begin(), finalNum.end(), compare);
    
    for(int i = 0; i <finalNum.size(); i++){
        answer += finalNum[i];
    }
    
    if (answer[0] == '0') {
        answer = '0';
    }
    
    return answer;
}