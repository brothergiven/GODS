#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer; //남은 수를 담을 배열생성

    
    answer.push_back(arr[0]); //첫번째 인덱스 복사
    
    for(int i = 1; i < arr.size(); i++){ //배열의 크기만큼 반복
        if(arr[i] != arr[i-1]){ //배열의 숫자가 연속적으로 나타나지 않을때
            answer.push_back(arr[i]); //남은 수를 담는 배열에 저장
        }
    }
    
    return answer;
}