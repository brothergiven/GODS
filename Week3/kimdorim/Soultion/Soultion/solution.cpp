#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string changed = s.substr(i) + s.substr(0, i);
        stack<char> a;

        for (auto c : changed) {
            if (c == '[' || c == '(' || c == '{' || a.empty())
                a.push(c);
            else {
                if (a.top() == ']' || a.top() == ')' || a.top() == '}')
                    break;

                if (a.top() == '[' && c == ']' || a.top() == '{' && c == '}' || a.top() == '(' && c == ')')
                    a.pop();

                else
                    a.push(c);
            }
        }

        if (a.empty())
            answer++;
    }
    return answer;
}