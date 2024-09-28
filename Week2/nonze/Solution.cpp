#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) { //string으로 비교 수행
	return a + b > b + a;
}

string solution(vector<int> numbers) { //가장 큰 수 - success
	string answer = "";
	vector<string> tmp;
    
	for (int i = 0; i < numbers.size(); i++) tmp.push_back(to_string(numbers[i]));
    
	sort(tmp.begin(), tmp.end(), cmp); //cmp 함수 기준으로 정렬 수행
    
	for (int i = 0; i < tmp.size(); i++) answer += tmp[i]; 
    
	if (answer[0] == '0') return "0"; //answer[0]가 0이면 가장 큰 수가 0이라는 뜻이므로 0리턴
    
	return answer;
}
