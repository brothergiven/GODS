#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;  // 최종 지도를 문자열 형태로 저장할 벡터
    
    // 지도 각 행을 순회
    for(int i = 0; i < n; i++)
    {
        string tmp = "";  // 해독한 한 행을 저장할 임시 문자열
        
        // 두 개의 지도 배열을 비트 OR 연산으로 결합
        arr1[i] = arr1[i] | arr2[i];
        
        // 결과 숫자를 2진수로 변환하여 벽('#')과 공백(' ')을 문자열로 변환
        // 2진수에서 짝수는 최하위 비트가 0, 홀수는 최하위 비트가 1
        while(tmp.size() != n)
        {
            if(arr1[i] % 2 == 0)  // 현재 비트가 0이면 공백 처리
                tmp.push_back(' ');
            else  // 현재 비트가 1이면 벽('#') 처리
                tmp.push_back('#');
            arr1[i] /= 2;  // 현재 확인한 최하위 비트를 제거하고 다음 비를 확인
        }
        
        // 2진수는 오른쪽에서 왼쪽으로 읽히므로 문자열을 반전하여 올바른 순서로 맞춤
        reverse(tmp.begin(), tmp.end());
        
        // 해독된 한 행을 최종 답안에 추가
        answer.push_back(tmp);
    }
    return answer;  // 해독된 전체 지도를 반환
}
