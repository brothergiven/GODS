#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> maze;

    for (int i = 0; i < n; i++) {
        int num = arr1[i] | arr2[i];
        maze.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (maze[i] & (1 << (n - 1 - j)))
                s += "#";
            else
                s += " ";
        }
        answer.push_back(s);
    }
    return answer;
}