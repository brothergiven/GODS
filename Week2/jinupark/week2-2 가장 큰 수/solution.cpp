/* 실행시간 초과로 폐기

#include <iostream>
#include <string>
#include <vector>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

using namespace std;

void perm(vector<string>& list, int i, int n, string& answer) {
    int j;

    string temp;

    if (i == n) {
        string current = "";
        for (j = 0; j <= n; j++) {

            current += list[j];

            if (answer == "" || current > answer) {
                answer = current;
            }
        }
    }
    else {
        for (j = i; j <= n; j++) {
            SWAP(list[i], list[j], temp);
            perm(list, i + 1, n, answer);
            SWAP(list[i], list[j], temp);
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> ans;
    for (int num : numbers) {
        ans.push_back(to_string(num));
    }

    perm(ans, 0, ans.size() - 1, answer);


    return answer;
}
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> ans;

    for (int num : numbers) {
        ans.push_back(to_string(num));
    }

    sort(ans.begin(), ans.end(), compare);

    string answer = "";
    for (string num : ans) {
        answer += num;
    }

    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}