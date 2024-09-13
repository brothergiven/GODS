#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    
    int answer = 0; //포장한 햄버거 개수
    
    for(int i=0; i < ingredient.size(); i++){ //쌓인 재료의 수만큼 반복
        if(ingredient[i] == 1 && ingredient[i+1] == 2 && ingredient[i+2] == 3 && ingredient[i+3] == 1){ //빵,야채, 고기, 빵 순으로 쌓였을 때 실행
            for(int j=0 ; j<4 ; j++){ //4번 반복
            ingredient.erase(ingredient.begin()+i); //빵, 야채, 고기, 빵 순으로 쌓인 인덱스의 값들을 제거
            }
            answer++; //포장한 햄버거 수 증가
            
            
            //햄버거를 포장한 후 남은 재료들을 다시 리서치하여 포장할 수 있는 햄버거들을 찾아보기 위해 i 값 수정
            //i 값을 앞으로 당겼을 때 인덱스가 음수가 되는 경우를 방지하기 위해 세분화하여 수정
            if(i>3)
               i-=4;
            if(i==0)
                i--;
            if(i==1)
                i-=2;
            if(i==2)
                i-=3;
           
            
           
        }
    }
  
    return answer;
}