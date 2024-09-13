#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0; // 포장된 햄버거의 개수를 저장할 변수
    vector<int> stack; // 현재 쌓인 재료를 저장할 스택 역할의 벡터

    // 모든 재료를 순차적으로 처리
    for (int i = 0; i < ingredient.size(); i++) {
        stack.push_back(ingredient[i]); // 재료를 스택에 추가
        
        // 스택의 마지막 4개의 재료가 햄버거의 순서(1, 2, 3, 1)에 맞는지 확인
        if (stack.size() >= 4 // 스택의 크기가 최소 4개 이상이어야 함
            && stack[stack.size()-1] == 1 // 마지막 재료가 빵(1)인지 확인
            && stack[stack.size()-2] == 3 // 그 앞이 고기(3)인지 확인
            && stack[stack.size()-3] == 2 // 그 앞이 야채(2)인지 확인
            && stack[stack.size()-4] == 1) { // 그 앞이 빵(1)인지 확인

            // 햄버거가 완성된 경우, answer 증가
            answer++;

            // 마지막 4개의 재료를 스택에서 제거
            stack.erase(stack.end()-4, stack.end());
        }
    }

    // 최종적으로 포장된 햄버거의 개수를 반환
    return answer;
}

/* 
모범답안
- 벡터에서 back()함수를 이용하여 매번 4개를 다 확인하지 않고 마지막 위치에 누적해서 하나의 요소로 보고 판단

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for(int x : ingredient){
        if(v.back() == 1 && x == 2) v.back() = 12;
        else if(v.back() == 12 && x == 3) v.back() = 123;
        else if(v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}

*/
