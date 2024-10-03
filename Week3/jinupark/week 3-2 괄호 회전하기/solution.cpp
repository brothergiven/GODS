#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string s) {

    stack<char> stack;

    for (auto a : s) {

        if (stack.empty())
            stack.push(a);

        else {

            if ((stack.top() == '[' && a == ']') || (stack.top() == '{' && a == '}') || (stack.top() == '(' && a == ')'))
                stack.pop();

            else
                stack.push(a);
        }
    }
    return stack.empty();
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1);

        if (isCorrect(b + a))
            answer += 1;
    }


    return answer;
}