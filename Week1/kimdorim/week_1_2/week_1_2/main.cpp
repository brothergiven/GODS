#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> arr = {4,4,4,3,3};
	vector<int> answer;
	int count=0; 
	for (int i = 0; i < arr.size(); i++) {
		if (answer.size() == 0 || arr[i] != answer[count-1])
		{
			answer.push_back(arr[i]);
			count++;
		}
	}
	cout << "answer = [";
	for (auto it = answer.begin(); it != answer.end(); it++) {
		cout << *it << " ";
	}
	cout << "]";
	return 0;
}
