#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for(int j=1; j<arr.size(); j++){
        if(arr[j]!=arr[j-1]) 
            answer.push_back(arr[j]);
    }

    return answer;
}


int main(){
    vector<int> arr;
    int n;
    int num;
    cin >> n;
    for( int i =0; i<n; i++){
        cin >> num;
        arr.push_back(num);
    }
    
    vector<int> result = solution(arr);
    for (int k =0; k<result.size(); k++){
        cout << result[k] << " ";
    }
    
    return 0;
    
}
