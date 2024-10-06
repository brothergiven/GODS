// 해당문제는 ( { [ 와 같이 여는 괄호는 스택에 푸쉬하고 짝이 맞는 괄호가 있으면 pop을 하여 구현을 하였습니다. 모든 문자열이 pop이 되면 올바른
// 문자열이라는 뜻이므로 st.empty()를 리턴해줍니다. 그리고 문자열을 돌면서 바로 pop이 가능한건 pop을 해주고 회전을 통하여 완성되는 문자열이 있다면 앞문자를 끝문자로 이어붙여서 새로운 문자열을 만들어 한바퀴씩 돌리는걸 구현해줍니다. 그렇게 생성된 문자열을 또 다시 CHECK 하고 s가 올바른 괄호 문자열일 경우 answer 값을 1씩 증가시킵니다.
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool checkS(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '[' || c == '{' || c == '(') {
            st.push(c);
        } 
        else if (c == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return false;
            }
        } 
        else if (c == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        } 
        else if (c == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (checkS(s)) {
            answer++;
        }
        string first = s.substr(0, 1);
        string second = s.substr(1, s.length() - 1);
        s = second + first;
    }
    
    return answer;
}
