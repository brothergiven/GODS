#include <algorithm>
#include <vector>

using namespace std;

int new_prior(vector<int>& vector) {
    int max = -1;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] > max) {
            max = vector[i];
        }
    }
    return max;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int prior = new_prior(priorities);

    while (true) {
        for (int i = 0; i < priorities.size(); ++i)
        {
            if (priorities[i] == prior) {

                answer++;
                priorities[i] = 0;
                prior = new_prior(priorities);

                if (location == i)
                    return answer;
            }
        }
    }
    return answer;
}