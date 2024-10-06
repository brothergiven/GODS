/*이 문제는 벽이 두 배열중 하나라도 있다면 해당 위치를 벽으로 인식해야하는 문제입니다. #가 있는 곳을 1로 #가 없는 곳을
0으로 하므로 해당 위치를 어떻게 구분하냐가 이 문제를 푸는데에 있어 핵심적인 부분입니다.
우선 arr1의 0번 인덱스 값을 2로 나누어 해당 값을 2진수로 표현하였을때 끝값이 짝수인지 홀수인지 확인합니다. 만약 홀수여서
나머지가 1이라면(2진수로 나타냈을때 마지막 비트가 1이라면) answer 배열에 #을 추가합니다. 그리고 해당 값을 2로 계속 나누어 예를들어 9라는 값을 입력받으면 1001(9) 100(4) 10(2) 1(1) 순서로 계산하여 #을 추가할지 ""을 추가할지 결정합니다.
그리고 최종적으로 answer 배열을 리턴해줍니다.
*/
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++)
    {
        answer.push_back("");
        for(int j=0;j<n;j++)
        {
            if(arr1[i] % 2 == 1 || arr2[i] % 2 == 1)
            {
                answer[i] = "#" + answer[i];
            }
            else{
                answer[i] = " " + answer[i];
            }
            arr1[i] = arr1[i] / 2;
            arr2[i] = arr2[i] / 2;
        }
    }
    return answer;
} 