#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) //정수형 벡터(arr)를 입력받아, 또 다른 정수형 벡터를 반환하는 함수
{
    vector<int> answer;      // 결과를 저장할 벡터를 생성
    answer.push_back(arr[0]);  // 배열의 첫 번째 값을 무조건 answer에 넣음

    for(int i=1; i<arr.size(); i++)   // 두 번째 값부터 배열 끝까지 반복
    {
        if(arr[i-1] != arr[i])        // 현재 값과 이전 값이 다르면
            answer.push_back(arr[i]); // 현재 값을 answer에 넣음
    }

    return answer;  // 중복되지 않은 결과값을 반환
}

/* 다른 풀이 
#include <vector>
#include <iostream>
#include <algorithm>  // STL의 unique, erase 함수를 사용하기 위한 헤더 파일

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // unique: 연속된 중복 요소를 제거하고 새로운 끝을 반환
    // erase: unique 함수가 반환한 새로운 끝부터 끝까지 요소를 삭제
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    // 중복이 제거된 벡터를 answer에 저장
    vector<int> answer = arr;

    // answer 벡터를 반환
    return answer;
} */
