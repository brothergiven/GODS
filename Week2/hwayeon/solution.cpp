#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 조합 했을때 가장 큰 수가 나올 수 있도록 함
bool compare(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    int n = numbers.size();
    vector<string> strArr(n);

    for (int i = 0; i < n; i++) {
        strArr[i] = to_string(numbers[i]);
    } // 정수 타입 원소를 문자열로 바꾸어 배열에 담기
    
    sort(strArr.begin(), strArr.end(), compare); // 정렬

    string answer;
    for (int i = 0; i < n; i++) {
        answer += strArr[i];
    } // 이어 붙이기

    if (answer[0] == '0') {
        answer = '0';
    } // numbers의 원소가 모두 0일 경우
    return answer;
}