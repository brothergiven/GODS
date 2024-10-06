#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i=0; i<n; i++) {
        int num = arr1[i] | arr2[i];
        string tmp = "";
        
        while (tmp.length() != n) {
            if (num % 2 == 0) tmp += " ";
            else tmp += "#";
            
            num /= 2;
        }
        
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }
    
    return answer;
}
