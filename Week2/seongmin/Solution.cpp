#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> indexLocation;
    vector<int> finalAnswer;

    for (int i = 0; i < priorities.size(); i++) {
        indexLocation.push(i);
    }

    while (!indexLocation.empty()) {
        int currentIndex = indexLocation.front();
        indexLocation.pop();
        int currentPriority = priorities[currentIndex];
        bool checkNotMax = false;

        for (int i = 0; i < priorities.size(); i++) {
            if (priorities[i] > currentPriority) {
                checkNotMax = true;
                break;
            }
        }

        if (checkNotMax) {
            indexLocation.push(currentIndex);
        } else {
            finalAnswer.push_back(currentIndex);
            priorities[currentIndex] = 0;
        }
    }

    for (int i = 0; i < finalAnswer.size(); i++) {
        if (finalAnswer[i] == location) return i + 1;
    }
}
