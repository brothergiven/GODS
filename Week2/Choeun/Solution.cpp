#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    int answer = 0;

    while (!q.empty()) {
        auto pick = q.front();
        q.pop();

        if (pick.first == pq.top()) {
            answer++;
            pq.pop();

            if (pick.second == location) {
                return answer;
            }
        }
        else {
            q.push(pick);
        }
    }

    return answer;
}